%token NL LP RP NUMBER
%token ADD SUB MUL DIV MOD POW //課題10-2でMOD, 課題10-3でPOWを追加
%%
list : 
     | list expr NL { printf("%d\n", $2);}
     ;
expr : expr ADD expr { $$ = $1 + $3;}
     | expr SUB expr { $$ = $1 - $3;}
     | expr MUL expr { $$ = $1 * $3;}     //課題10-1
     | expr DIV expr { $$ = $1 / $3;}     //課題10-1
     | expr MOD expr { $$ = $1 % $3;}     //課題10-2
     | expr POW expr { $$ = pow($1, $3);} //課題10-3
     | LP expr RP    { $$ = $2;}
     | NUMBER        { $$ = $1;}
     ;
%%
#include <math.h>   //課題10-3
#include "lex.yy.c"
