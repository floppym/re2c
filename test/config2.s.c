/* Generated by re2c */
#line 1 "config2.s.re"
#define	NULL		((char*) 0)
#define	YYCTYPE		char
#define	YYCURSOR	p
#define	YYLIMIT		p
#define	YYMARKER	q
#define	YYFILL(n)

char *scan0(char *p)
{
	char *q;

#line 15 "<stdout>"
{
   YYCTYPE yych;
   goto yy0;
   ++YYCURSOR;
yy0:
   if(YYLIMIT == YYCURSOR) YYFILL(1);
   yych = *YYCURSOR;
   if(yych <= 'b') {
      if(yych <= '`') goto yy10;
      if(yych >= 'b') goto yy4;
      goto yy2;
   } else {
      if(yych <= 'c') goto yy6;
      if(yych <= 'd') goto yy8;
      goto yy10;
   }
yy2:
   ++YYCURSOR;
   goto yy3;
yy3:
#line 13 "config2.s.re"
   { return YYCURSOR; }
#line 38 "<stdout>"
yy4:
   ++YYCURSOR;
   goto yy5;
yy5:
#line 14 "config2.s.re"
   { return YYCURSOR; }
#line 45 "<stdout>"
yy6:
   ++YYCURSOR;
   goto yy7;
yy7:
#line 15 "config2.s.re"
   { return YYCURSOR; }
#line 52 "<stdout>"
yy8:
   ++YYCURSOR;
   goto yy9;
yy9:
#line 16 "config2.s.re"
   { return YYCURSOR; }
#line 59 "<stdout>"
yy10:
   ++YYCURSOR;
   goto yy11;
yy11:
#line 17 "config2.s.re"
   { return NULL; }
#line 66 "<stdout>"
}
#line 18 "config2.s.re"

}

char *scan1(char *p)
{
	char *q;

#line 76 "<stdout>"
{
	YYCTYPE yych;
	goto yy12;
	++YYCURSOR;
yy12:
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'b') {
		if(yych <= '`') goto yy22;
		if(yych >= 'b') goto yy16;
		goto yy14;
	} else {
		if(yych <= 'c') goto yy18;
		if(yych <= 'd') goto yy20;
		goto yy22;
	}
yy14:
	++YYCURSOR;
	goto yy15;
yy15:
#line 26 "config2.s.re"
	{ return YYCURSOR; }
#line 99 "<stdout>"
yy16:
	++YYCURSOR;
	goto yy17;
yy17:
#line 27 "config2.s.re"
	{ return YYCURSOR; }
#line 106 "<stdout>"
yy18:
	++YYCURSOR;
	goto yy19;
yy19:
#line 28 "config2.s.re"
	{ return YYCURSOR; }
#line 113 "<stdout>"
yy20:
	++YYCURSOR;
	goto yy21;
yy21:
#line 29 "config2.s.re"
	{ return YYCURSOR; }
#line 120 "<stdout>"
yy22:
	++YYCURSOR;
	goto yy23;
yy23:
#line 30 "config2.s.re"
	{ return NULL; }
#line 127 "<stdout>"
}
#line 31 "config2.s.re"

}

char *scan(char *p)
{
	char *q;

#line 137 "<stdout>"
{
YYCTYPE yych;
goto yy24;
++YYCURSOR;
yy24:
if(YYLIMIT == YYCURSOR) YYFILL(1);
yych = *YYCURSOR;
if(yych <= 'b') {
if(yych <= '`') goto yy34;
if(yych >= 'b') goto yy28;
goto yy26;
} else {
if(yych <= 'c') goto yy30;
if(yych <= 'd') goto yy32;
goto yy34;
}
yy26:
++YYCURSOR;
goto yy27;
yy27:
#line 39 "config2.s.re"
{ return YYCURSOR; }
#line 160 "<stdout>"
yy28:
++YYCURSOR;
goto yy29;
yy29:
#line 40 "config2.s.re"
{ return YYCURSOR; }
#line 167 "<stdout>"
yy30:
++YYCURSOR;
goto yy31;
yy31:
#line 41 "config2.s.re"
{ return YYCURSOR; }
#line 174 "<stdout>"
yy32:
++YYCURSOR;
goto yy33;
yy33:
#line 42 "config2.s.re"
{ return YYCURSOR; }
#line 181 "<stdout>"
yy34:
++YYCURSOR;
goto yy35;
yy35:
#line 43 "config2.s.re"
{ return NULL; }
#line 188 "<stdout>"
}
#line 44 "config2.s.re"

}