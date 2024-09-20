#include <stdio.h> 

double work(const int time, double I, double U);
int main(void) 
{ 
    const int time = 1200.0;
    double I; 
    double U;
    scanf("%lf", &I);
    scanf("%lf", &U);
    printf("%lf", work(time, I, U));

    return 0;
}
double work(const int time, double I, double U)
{ 
    return U * I * time;
}