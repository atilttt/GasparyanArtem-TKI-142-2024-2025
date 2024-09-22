#include <stdio.h>
/*
 * @brief расчитывает деление массы на дюйм
 * @param inch значение константы inch
 * @param x значение переменной x
 * @return рассчитаное значение
 */
double result(double x);
/*
 * @brief вход в программу
 * @return 0 в случае успеха
 */
int main(void) 
{ 
    double x;
    printf("Введите вес в граммах:");
    scanf("%lf", &x);
    printf("%lf", result(x));

    return 0;
}

double result(double x)
{
    const double inch = 28.3; 
    return x / inch;
}