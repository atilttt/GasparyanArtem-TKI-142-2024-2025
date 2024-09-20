#include <stdio.h>
double result(const double inch, double x);
int main(void) 
{ 
    const double inch = 28.3;
    double x;
    printf("Введите вес в граммах:");
    scanf("%lf", &x);
    printf("%lf", result(inch, x));

    return 0;
}

double result(const double inch, double x)
{ 
    return x / inch;
}