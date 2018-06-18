#include <stdio.h>

int max2(int a, int b, int c)
{
    //ここに課題のプログラムを書く
}

int main(void)
{
    printf("---max2 for a---\n");
    printf("%d\n", max2(30, 20, 10));
    printf("%d\n", max2(30, 10, 20));
    printf("%d\n", max2(30, 15, 15));
    printf("%d\n", max2(30, 30, 5));
    printf("%d\n", max2(30, 5, 30));
    printf("%d\n", max2(30, 30, 30));
    printf("---max2 for b---\n");
    printf("%d\n", max2(20, 30, 10));
    printf("%d\n", max2(10, 30, 20));
    printf("%d\n", max2(15, 30, 15));
    printf("%d\n", max2(30, 30, 5));
    printf("%d\n", max2(5, 30, 30));
    printf("%d\n", max2(30, 30, 30));
    printf("---max2 for c---\n");
    printf("%d\n", max2(20, 10, 30));
    printf("%d\n", max2(10, 20, 30));
    printf("%d\n", max2(15, 15, 30));
    printf("%d\n", max2(30, 5, 30));
    printf("%d\n", max2(5, 30, 30));
    printf("%d\n", max2(30, 30, 30));

    return 0;
}
