%%
"m" return MAX; 
"t" return TRI; //課題11-1
"s" return SUM; //課題11-2
"r" return RAN; //課題11-3
"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"%" return MOD;
"(" return LP;
")" return RP;
"\n" return NL;

[0-9]+ {
  yylval = atoi(yytext);
  return NUMBER;
}
%%
