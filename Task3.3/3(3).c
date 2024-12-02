#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
#include <float.h>

/**
 * @brief получает на вход число из потока ввода 
 * @return возвращает полученное число, иначе вернет ошибку
 */
double input(void);

/**
 * @brief функция, проверяющая заданный интервал
 * @param a начальная точка заданного интервала
 * @param b конечная точка заданного интервала
 */
void interval_check(const double a, const double b);

/**
 * @brief функция, проверяющая заданный шаг 
 * @param step значение заданного шага
 */
void check_step(const double step);

/**
 * @brief рассчитывает значение функции в заданной точке
 * @param x значение аргумента
 * @return рассчитанное значение функции
 */
double get_function(const double x);

/**
 * @brief рассчитывает рекуррентное выражение
 * @param x значение аргумента 
 * @param k значение индекса элемента
 * @return рассчитанное рекуррентное значение
 */
double get_current(const double x, const int k);

/**
 * @brief рассчитывает сумму функционального ряда
 * @param x точка, в которой нужно вычислить сумму ряда
 * @param eps заданная точность 
 * @return рассчитанное значение суммы функционального ряда
 */
double get_sum_func_row(const double x, const double eps);

/** 
 * @brief Главная точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    const double eps = 1e-5; // более читаемая запись для точности
    printf("Please enter interval values (start and end):\n");
    const double a = input(); 
    const double b = input();
    printf("Please enter step value:\n");
    const double step = input();

    // Проверка входных данных
    interval_check(a, b);
    check_step(step);

    printf("\n**Results**\n");

    // Итерация по точкам в заданном интервале с шагом
    for (double x = a; x <= b + DBL_EPSILON; x += step)
    {
        if (fabs(x) >= 1.0 - DBL_EPSILON)  { // Проверка области определения функции (ООФ)
            printf("x = %.2f: the function does not exist at this point\n", x);
        } else {
            printf("x = %.2f\tf(x) = %.6f\tS(x) = %.6f\n", 
                   x, get_function(x), get_sum_func_row(x, eps));
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
        perror("Input error\n");
        exit(EXIT_FAILURE);
    }

    return value;
}

void interval_check(const double a, const double b)
{ 
    if (a >= b) // a должно быть меньше b
    {
        errno = EINVAL; 
        perror("Interval value is set incorrectly\n");
        exit(EXIT_FAILURE);
    }
}

void check_step(const double step)
{
    if (step <= DBL_EPSILON) // Шаг должен быть положителен и больше машинного эпсилона
    { 
        errno = EINVAL; 
        perror("Step value is set incorrectly\n");
        exit(EXIT_FAILURE);
    }
}

double get_function(const double x)
{   
    // Основная функция
    return (1.0 / 4.0) * log((1 + x) / (1 - x)) + (1.0 / 2.0) * atan(x); 
}

double get_current(const double x, const int k)
{ 
    // Расчет элемента ряда
    return pow(x, 4 * k + 1) / (4 * k + 1);
}

double get_sum_func_row(const double x, const double eps)
{ 
    // Переменные для текущего элемента и суммы
    double current = get_current(x, 0); 
    double sum = 0.0;
    int k = 0; // Начинаем с k = 0

    while (fabs(current) >= eps)
    { 
        sum += current;
        k++; // Переходим к следующему индексу
        current = get_current(x, k); 
    } 

    return sum; // Возвращаем сумму
}
