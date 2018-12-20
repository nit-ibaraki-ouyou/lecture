%%
"clear" return CLEAR;
"exit" return EXIT;
"\n" return NL;

[0-9]+ {
  yylval = atoi(yytext);
  return NUMBER;
}
%%
