#include <stdio.h>
#define N 7

void show(char *label[], int value[], int size);

void show(char *label[], int value[], int size)
{
    int i;
    for(i=0; i<size; i++) {
        printf("label: %s, ", label[i]);
        printf("value: %d\n", value[i]);
    }
}

int main(void)
{
  char *dates1[N] = {"7/17", "7/18", "7/19", "7/20", "7/21", "7/22", "7/23"};
  int temperature1[N] = {36, 35, 34, 34, 35, 34, 34};

  printf("---show---\n");
  show(dates1, temperature1, N);

  return 0;
}
