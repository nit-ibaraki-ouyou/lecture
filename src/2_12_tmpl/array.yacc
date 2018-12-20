%token NL NUMBER
%token CLEAR EXIT
%%
list :
     | list cmd NL       { printf("\n"); }
     ;
cmd  : CLEAR             { clear(); }
     | EXIT              { exit(0); }
     ;
%%
#include <stdio.h>
#include "lex.yy.c"
#include "myproc.h"
