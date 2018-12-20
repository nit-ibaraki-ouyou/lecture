%%
"clear" return CLEAR;
"exit" return EXIT;
"show" return SHOW;
"set"  return SET;
"sum"  return SUM;
"set2" return SET2;
"ave"  return AVE;
"\n" return NL;

[0-9]+ {
  yylval = atoi(yytext);
  return NUMBER;
}
%%
