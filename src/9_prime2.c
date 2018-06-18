#include <stdio.h>
#include <math.h>

#define N 100
void prime2(int *a, int num);

void prime2(int *a, int num)
{
    int i, j;
    double goal;
    for(i=0; i<=num; i++) {
	a[i] = i;
    }
    goal = sqrt(num);
    for(i=2; i<goal; i++) {
	//ここに課題のプログラムを追加する
    }
}

int main(void)
{
    int i;
    int a[N];
    prime2(a, N);
    for(i=2; i<=N; i++) {
	printf("%d, ", a[i]);
    }
    printf("\n");

    return 0;
}
