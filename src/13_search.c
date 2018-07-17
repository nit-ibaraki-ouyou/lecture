#include <stdio.h>
#define N 7

void search(char *label[], int value[], int n, int size);

void search(char *label[], int value[], int n, int size)
{
    int i = 0;
    while(1) {
        if(value[i]==n) {
            printf("label: %s, ", label[i]);
            printf("value: %d\n", value[i]);
            break;
        }
        if(i==size-1) {
            printf("見つかりませんでした\n");
            break;
        }
        i++;
    }
}

int main(void)
{
  char *dates1[N] = {"7/17", "7/18", "7/19", "7/20", "7/21", "7/22", "7/23"};
  int temperature1[N] = {36, 35, 34, 34, 35, 34, 34};

  search(dates1, temperature1, 34, N);
  search(dates1, temperature1, 29, N);

  return 0;
}
