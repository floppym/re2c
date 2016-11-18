#include <algorithm>
#include <string.h>

#include "src/ir/dfa/dfa.h"
#include "src/ir/skeleton/path.h"
#include "src/ir/skeleton/skeleton.h"

namespace re2c
{

Node::Node()
	: arcs()
	, rule(Rule::NONE)
	, cmd(NULL)
{}

static bool same(const tcmd_t &x, const tcmd_t &y)
{
	return x.save == y.save && x.copy == y.copy;
}

void Node::init(const dfa_state_t *s, const charset_t &cs, size_t nil)
{
	const size_t nc = cs.size() - 1;
	for (uint32_t c = 0, l = 0; c < nc;) {

		size_t j = s->arcs[c];
		const tcmd_t &t = s->tcmd[c];
		for (; ++c < nc && s->arcs[c] == j && same(s->tcmd[c], t););
		if (j == dfa_t::NIL) j = nil;

		// all arcs go to default node => this node is final
		if (l == 0 && c == nc && j == nil) break;

		const uint32_t u = cs[c];
		arcs[j].push_back(Node::range_t(l, u - 1, &t));

		l = u;
	}

	rule = s->rule;
	cmd = &s->tcmd[nc];
}

bool Node::end() const
{
	return arcs.size() == 0;
}

const size_t Skeleton::DEFTAG = std::numeric_limits<size_t>::max();

Skeleton::Skeleton(
	const dfa_t &dfa,
	const charset_t &cs,
	size_t def,
	const std::string &dfa_name,
	const std::string &dfa_cond,
	uint32_t dfa_line)
	: name(dfa_name)
	, cond(dfa_cond)
	, line(dfa_line)
	, nodes_count(dfa.states.size() + 1) // +1 for default state
	, nodes(new Node[nodes_count])
	, sizeof_key(8)
	, defrule(def)
	, ntagver(static_cast<size_t>(dfa.maxtagver) + 1)
	, rules(dfa.rules)
	, tags(dfa.tags)
{
	// initialize nodes
	const size_t nil = nodes_count - 1;
	for (size_t i = 0; i < nil; ++i) {
		nodes[i].init(dfa.states[i], cs, nil);
	}

	// initialize size of key
	const size_t maxlen = maxpath(*this);
	const size_t maxrule = dfa.rules.size() + 1; // +1 for none-rule
	const size_t max = std::max(maxlen, maxrule);
	if (max <= std::numeric_limits<uint8_t>::max()) {
		sizeof_key = 1;
	} else if (max <= std::numeric_limits<uint16_t>::max()) {
		sizeof_key = 2;
	} else if (max <= std::numeric_limits<uint32_t>::max()) {
		sizeof_key = 4;
	}
}

Skeleton::~Skeleton()
{
	delete[] nodes;
}

size_t rule2key(size_t rule, size_t key, size_t def)
{
	switch (key) {
		default: assert(false); // shouldn't happen
		case 8: return rule2key<uint64_t>(rule, def);
		case 4: return rule2key<uint32_t>(rule, def);
		case 2: return rule2key<uint16_t>(rule, def);
		case 1: return rule2key<uint8_t>(rule, def);
	}
}

} // namespace re2c
