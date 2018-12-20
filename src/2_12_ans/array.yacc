%token NL NUMBER
%token CLEAR EXIT SHOW SET SUM SET2 AVE
%%
list :
     | list cmd NL       { printf("\n"); }
     ;
cmd  : CLEAR             { clear(); }
     | EXIT              { exit(0); }
     | SHOW              { show(); }
     | SET NUMBER NUMBER { set($2, $3); }
     | SUM               { sum(); }
     | SET2 NUMBER NUMBER NUMBER { set2($2, $3, $4); }
     | AVE               { ave(); }
     ;
%%
#include <stdio.h>
#include "lex.yy.c"
#include "myproc.h"
