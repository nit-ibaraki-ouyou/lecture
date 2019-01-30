%token NL LP RP NUMBER
%token ADD SUB MUL DIV MOD POW
%%
list : 
     | list expr NL { printf("%d\n", $2);}
     ;
expr : ADD expr expr { $$ = $2 + $3;}     //演算子を前にして$1を$2に変更する
     | SUB expr expr { $$ = $2 - $3;}     //同様
     | MUL expr expr { $$ = $2 * $3;}     //同様
     | DIV expr expr { $$ = $2 / $3;}     //同様
     | MOD expr expr { $$ = $2 % $3;}     //同様
     | POW expr expr { $$ = pow($2, $3);} //同様
     | LP expr RP    { $$ = $2;}
     | NUMBER        { $$ = $1;}
     ;
%%
#include <math.h>
#include "lex.yy.c"
