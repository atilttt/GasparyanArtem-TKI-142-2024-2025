#include <stdio.h>

/**
 * @brief перевод значения веса в граммах в унции
 * @param inch значение 1 унция
 * @param x вес в граммах
 * @return возвращает рассчитаное значение
 */
double result(double x);

/**
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
    const double unz = 28.3; 
    return x / unz;
}