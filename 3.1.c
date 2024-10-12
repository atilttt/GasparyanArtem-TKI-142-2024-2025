#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <errno.h>
#include <float.h>

/**
 * @brief получает на вход значение
 * @return возвращает полученное значение, в противном случае ошибку
 */
double input(void);

/**
 * @brief проверяет корретность заданного интервала
 * @param start начальное значение заданного интервала
 * @param end конечное значение заданного интервала
 * @return в случае некорректно заданного интервала, возвращает ошибку
 */
void interval_chek(const double start, const double end);

/**
 * @brief проверят корректность заданого шага
 * @param step значение шага
 * @return в случае некорректно заданного шага, возвращает ошибку
 */
void step_chek(const double step);

/**
 * @brief проверяет значение заданного параметра x
 * @param x значение параметра х
 * @return возвращает True, если все введенно корректно, в противном случае вернет False
 */
bool chek_value_x(double x);

/**
 * @brief рассчитывает значение заданной фукнции
 * @param x значение переменной x
 * @return рассчитанное значение функции
 */
double get_function(double x);


int main()
{
    printf("please enter interval value\n"); 
    const double start = input();
    const double end = input();
    printf("please enter step\n");
    const double step = input();
    double x = 0.0;

    for (x = start; x <= end + DBL_EPSILON; x += step)
    { 
        if (chek_value_x(x) == false)
        {
            puts("x input error");
            exit(EXIT_FAILURE);
        }
        else { 
            printf("In point x = %.3lf, value function y = %.3lf\n", x, get_function(x));
        }
    }

    return 0;
}                                                                   

double input(void)
{ 
    double value = 0.0;
    int result = scanf("%lf", &value);
    if (result != 1)
    { 
        errno = EIO;
        perror("Inpur error value\n");
        exit(EXIT_FAILURE);
    }
    
    return value;
}

void interval_check(const double start, const double end)
{ 
    if (end - start < DBL_EPSILON)
    {
        errno = EIO;
        perror("interval input error\n");
        exit(EXIT_FAILURE);
    }
}

void step_chek(const double step)
{ 
    if (step < 0)
    { 
        errno = EIO;
        perror("step input error\n");
        exit(EXIT_FAILURE);
    }
}

bool chek_value_x(double x)
{
    return x > 0; 
}

double get_function(double x)
{ 
    return cos(x/ 2) - 2 * sin(1 / x) + 1 / x; 
}