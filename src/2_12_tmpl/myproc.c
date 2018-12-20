#include <stdio.h>
#include "myproc.h"

int clear()
{
    int i;
    for(i=0; i<10; i++) {
	a[i] = 0;
    }
    return 0;
}
