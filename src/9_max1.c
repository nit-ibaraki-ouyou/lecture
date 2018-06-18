#include <stdio.h>

int max1(int a, int b, int c)
{
    int result = -1;
    //aが最大値の場合の条件
    if((a > b && b > c)  ||
       (a > c && c > b)  ||
       (a > b && b == c) ||
       (a == b && b > c) ||
       (a == c && c > b) ||
       (a == b && b == c)) {
	result = a;
    }
    return result;
}

int main(void)
{
    printf("---max1 for a---\n");
    printf("%d\n", max1(30, 20, 10));
    printf("%d\n", max1(30, 10, 20));
    printf("%d\n", max1(30, 15, 15));
    printf("%d\n", max1(30, 30, 5));
    printf("%d\n", max1(30, 5, 30));
    printf("%d\n", max1(30, 30, 30));
    printf("---max1 for b---\n");
    printf("%d\n", max1(20, 30, 10));
    printf("%d\n", max1(10, 30, 20));
    printf("%d\n", max1(15, 30, 15));
    printf("%d\n", max1(30, 30, 5));
    printf("%d\n", max1(5, 30, 30));
    printf("%d\n", max1(30, 30, 30));
    printf("---max1 for c---\n");
    printf("%d\n", max1(20, 10, 30));
    printf("%d\n", max1(10, 20, 30));
    printf("%d\n", max1(15, 15, 30));
    printf("%d\n", max1(30, 5, 30));
    printf("%d\n", max1(5, 30, 30));
    printf("%d\n", max1(30, 30, 30));

    return 0;
}
