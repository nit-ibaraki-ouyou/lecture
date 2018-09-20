#include <stdio.h>

void show(int value[], int size);
void swap(int *x, int *y);
void bubble(int value[], int size);

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

void bubble(int value[], int size)
{
    int i, j, n;
    n = size-1;
    for(i=0; i<size-1; i++) {
	for(j=0; j<n; j++) {
	    if(value[j] > value[j+1]) {
		swap(&value[j], &value[j+1]);
	    }
	}
	n--;
    }
}

int main(void)
{
    int v[10] = {9, 7, 6, 0, 1, 5, 2, 3, 4, 8};
    show(v, 10);

    int a = 10;
    int b = 20;
    printf("（交換前）a: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("（交換後）a: %d, b: %d\n", a, b);

    bubble(v, 10);
    show(v, 10);

    return 0;
}
