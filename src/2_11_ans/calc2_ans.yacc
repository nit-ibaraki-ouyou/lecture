%token NL LP RP NUMBER
%token ADD SUB MUL DIV MOD MAX TRI SUM RAN //課題で追加する
%%
list : 
     | list expr NL { printf("%d\n", $2);}
     ;
expr : expr ADD expr { $$ = $1 + $3;}
     | expr SUB expr { $$ = $1 - $3;}
     | expr MUL expr { $$ = $1 * $3;}
     | expr DIV expr { $$ = $1 / $3;}
     | expr MOD expr { $$ = $1 % $3;}
     | MAX expr expr { $$ = max($2, $3);}
     | TRI expr expr expr { $$ = tri($2, $3, $4);} //課題11-1
     | SUM expr      { $$ = sum($2);} //課題11-2
     | RAN expr expr { $$ = range($2, $3);} //課題11-3
     | LP expr RP    { $$ = $2;}
     | NUMBER        { $$ = $1;}
     ;
%%
#include <stdio.h>
#include "lex.yy.c"
#include "myproc.h"
