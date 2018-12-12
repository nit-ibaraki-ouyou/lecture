%token NL LP RP NUMBER
%token ADD SUB MUL DIV MOD MAX
%%
list : 
     | list expr NL { printf("%d\n", $2);}
     ;
expr : expr ADD expr { $$ = $1 + $3;}
     | expr SUB expr { $$ = $1 - $3;}
     | expr MUL expr { $$ = $1 * $3;}
     | expr DIV expr { $$ = $1 / $3;}
     | expr MOD expr { $$ = $1 % $3;}
     | MAX expr expr { $$ = max($2, $3); }
     | LP expr RP    { $$ = $2;}
     | NUMBER        { $$ = $1;}
     ;
%%
#include "lex.yy.c"
#include "myproc.h"
