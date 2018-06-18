#include <stdio.h>

#define N 100
int isprime(int num);

int isprime(int num)
{
    //ここに課題のプログラムを書く
    int i;
}

int main(void)
{
    int i;
    for(i=2; i<=N; i++) {
	printf("%d, ", isprime(i));
    }
    printf("\n");

    return 0;
}
