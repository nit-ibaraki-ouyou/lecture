#include <stdio.h>
#define N 7

void banpei(char *label[], int value[], int n, int size);

void banpei(char *label[], int value[], int n, int size)
{
    int i = 0;
    while(1) {
        if(value[i]==n) {
            if(i != size) {
                printf("label: %s, ", label[i]);
                printf("value: %d\n", value[i]);
            } else {
                printf("見つかりませんでした\n");
            }
            break;
        }
        i++;
    }
}

int main(void)
{
    char *dates1[N+1] = {"7/17", "7/18", "7/19", "7/20", "7/21", "7/22", "7/23", ""};
    int temperature1[N+1] = {36, 35, 34, 34, 35, 34, 34, 34};

    banpei(dates1, temperature1, 34, N);
    banpei(dates1, temperature1, 29, N);

    return 0;
}
