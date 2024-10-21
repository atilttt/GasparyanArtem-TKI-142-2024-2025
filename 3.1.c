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
 * @brief проверяет заданное число на положительность
 * @return возвращает проверенное число, в ином случаешь завершает программу и пишет ошибку
 */
double pozitiv_double(void);

/**
 * @brief проверяет корретность заданного интервала
 * @param start начальное значение заданного интервала
 * @param end конечное значение заданного интервала
 * @return в случае некорректно заданного интервала, возвращает ошибку
 */
void interval_check(const double start, const double end);

/**
 * @brief проверяет значение заданного параметра x
 * @param x значение параметра х
 * @return возвращает True, если все введенно корректно, в противном случае вернет False
 */
bool check_value_x(const double x);

/**
 * @brief рассчитывает значение заданной фукнции
 * @param x значение переменной x
 * @return рассчитанное значение функции
 */
double get_function(const double x);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    printf("please enter interval value\n"); 
    const double start = input();
    const double end = input();
    interval_check(start, end);
    printf("please enter step\n");
    const double step = input();
    double x = 0.0; 

    for (x = start; x + DBL_EPSILON <= end; x += step)
    { 
        if (!check_value_x(x))
        {
            puts("x input error");
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
        perror("Input error value\n");
        exit(EXIT_FAILURE);
    }
    
    return value;
}

double pozitiv_double(void)
{
    double value = input();
    if (value < DBL_EPSILON)
    { 
        errno = EIO;
        perror("Input error\n");
        exit(EXIT_FAILURE);
    }

    return value;
}

void interval_check(const double start, const double end)
{ 
    if (end - start < DBL_EPSILON)
    {
        errno = EIO;
        perror("Interval input error\n");
        exit(EXIT_FAILURE);
    }
}

void step_check(const double step)
{ 
    if (step <= DBL_EPSILON)
    { 
        errno = EIO;
        perror("Step input error\n");
        exit(EXIT_FAILURE);
    }
}

bool check_value_x(const double x)
{
    return x > DBL_EPSILON; 
}

double get_function(const double x)
{ 
    return cos(2 / x) - 2 * sin(1 / x) + 1 / x; 
}
