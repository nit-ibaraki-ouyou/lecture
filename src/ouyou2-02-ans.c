#include <stdio.h>

void show(int value[], int size);
void swap(int *x, int *y);
void quick(int value[], int left, int right);

void show(int value[], int size)
{
    int i;
    for(i=0; i<size; i++) {
	printf("%d ", value[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void quick(int value[], int left, int right)
{
    int x = value[(left+right)/2];
    int pl = left;
    int pr = right;
    
    while(1) {
        while(value[pl] < x) pl++;
        while(value[pr] > x) pr--;
        if(pl > pr) {
            break;
        }
        if(pl <= pr) {
            swap(&value[pl], &value[pr]);
            pl++;
            pr--;
        }
    }
    if(left < pr) quick(value, left, pr);
    if(pl < right) quick(value, pl, right);
}

int main(void)
{
    int v[10] = {9, 7, 6, 0, 1, 5, 2, 3, 4, 8};
    show(v, 10);
    quick(v, 0, 9);
    show(v, 10);

    return 0;
}
