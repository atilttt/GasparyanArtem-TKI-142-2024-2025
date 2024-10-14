#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <math.h> 
#include <float.h> 
#include <stdbool.h>

/**
 * @brief получает число из потока ввода
 * @return возвращает проверенное число
 */
double input(void);

/**
 * @brief проверяет корректность заданного шага
 * @param step - заданный шаг
 * @return dвозвращает ошибку, если шаг задан некорректно
 */
void chek_step(const double step);

/**
 * @brief проверяет корректность заданного интервала
 * @param start начальная точка интервала
 * @param end 
 * @return 
 */
void chek_interval(const double start, const double end);

/**
 * @brief рассчитывает значение функции в точке х
 * @param х значение параметра х
 * @return рассчитанное значение функции
 */
double function(const double x);

int main(void)
{ 
    printf("Please enter value x:\n");
    const double x = input(); 
    printf("Please enter interval:\n start: \n end: \n");
    const double start = input();
    const double end = input();
    printf("Please enter value step:\n");
    const double step = input();
    const double E = pow(30, -5);



    return 0;
}