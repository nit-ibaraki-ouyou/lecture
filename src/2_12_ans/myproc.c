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

int show(void)
{
    int i;
    for(i=0; i<10; i++) {
	printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

int set(int i, int n)
{
    a[i] = n;
    return 0;
}

int sum()
{
    int r = 0;
    int i;
    for(i=0; i<10; i++) {
	r += a[i];
    }
    printf("%d\n", r);
    return 0;
}

int set2(int s, int e, int n)
{
    int i;
    for(i=s; i<=e; i++) {
	a[i] = n;
    }
    return 0;
}

int ave()
{
    double r = 0;
    int i;
    for(i=0; i<10; i++) {
	r += a[i];
    }
    r = r / 10;
    printf("%lf\n", r);
    return 0;
}
