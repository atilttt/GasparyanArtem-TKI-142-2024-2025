#include <stdio.h>
/*
 * @brief расчитывает деление массы на дюйм
 * @param inch значение константы inch
 * @param x значение переменной x
 * @return рассчитаное значение
 */
double result(const double inch, double x);
/*
 * @brief вход в программу
 * @return 0 в случае успеха
 */
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