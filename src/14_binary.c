#include <stdio.h>
#define N 7

void binary(char *label[], int value[], int n, int left, int right);

void binary(char *label[], int value[], int n, int left, int right)
{
    int center;
    while(1) {
        if(left>right) {
            printf("見つかりませんでした\n");
            return;
        }       
        center = (left+right)/2;
        if(value[center]==n) {
            printf("label: %s, ", label[center]);
            printf("value: %d\n", value[center]);
            return;
        }
        if(value[center]>n) {
            right = center-1;
        }
        if(value[center]<n) {
            left = center+1;
        }
    }
}

int main(void)
{
    char *l[N] = {"num0", "num1", "num2", "num3", "num4", "num5", "num6"};
    int v[N] = {5, 9, 13, 14, 16, 17, 20};

    binary(l, v, 5, 0, N-1);
    binary(l, v, 20, 0, N-1);
    binary(l, v, 10, 0, N-1);

    return 0;
}
