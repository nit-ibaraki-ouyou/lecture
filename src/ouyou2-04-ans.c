#include <stdio.h>

double mysqrt(double c);
double mysqrt2(double c);

double mysqrt(double c)
{
    int i;
    double x1, x2;
    x1 = 100;
    for(i=0; i<20; i++) {
	x2 = x1 - (x1*x1 - c) / (2*x1);
	x1 = x2;
	printf("%d: %lf\n", i, x2);
    }
    return x2;
}

double mysqrt2(double c)
{
    int i;
    double x1, x2;
    x1 = 100;
    for(i=0; 1; i++) {
	x2 = x1 - (x1*x1 - c) / (2*x1);
	printf("%d: %lf\n", i, x2);
	if(x1-x2<0.0001) break;
	x1 = x2;
    }
    return x2;
}

int main(void)
{
    printf("%lf\n", mysqrt(2));
    printf("%lf\n", mysqrt(3));
    printf("%lf\n", mysqrt(4));
    printf("%lf\n", mysqrt(5));

    printf("%lf\n", mysqrt2(2));
    printf("%lf\n", mysqrt2(3));
    printf("%lf\n", mysqrt2(4));
    printf("%lf\n", mysqrt2(5));

    return 0;
}
