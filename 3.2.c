#include <stdio.h>
#include <math.h>
#include <errno.h>  
#include <stdlib.h>
#include <float.h> 

/**
 * @brief получает на вход число из потока ввода
 * @return возвращает проверенное число, в противном случае ошибку
 */
double input(void);

/**
 * @brief получает на вход число из потока ввода
 * @return возвращает провернное число, в противном случае ошибку 
 */
int integer_input(void);

/**
 * @brief проверяет заданное число на положительность
 * @return возвращает проверенное число, в ином случае завершает программу и пишет ошибку
 */
int positive_int(void);

/**
 * @brief проверяет заданное число на положительность 
 * @return возвращает проверенное число, в ином случае завершает программу и пишет ошибку
 */
double pozitive_double(void);

/**
 * @brief вычисляет следующий член последовательности при помощи рекуррентного выражения
 * @param previous_term значение предыдущего члена последовательности
 * @param k текущий индекс последовательности
 * @return значение следующего члена последовательности
 */
double next_term(const double previous_term, const int k); // добавлено const //

/**
 * @brief рассчитывает значение суммы первых n-членов последовательности
 * @param n кол-во элементов последовательности
 * @return рассчитанное значение суммы
 */
double get_sum_first_n(const int n);

/**
 * @brief рассчитывает значение суммы всех членов последовательности, не меньше заданного числа е
 * @param n кол-во элементов последовательности
 * @param e значение заданного числа е
 * @return рассчитанное значение суммы
 */
double get_sum_dependet_e(const int n, const double e);

/**
 * @brief точка входа в программу 
 * @return 0 в случае успеха
 */
int main(void)
{
    printf("Please enter the number of sequence elements:\n");
    const int n = Integer_Input();
    printf("Please enter value e:\n");
    const double e = input();
    pozitiv_double(e); // проверка epslion обьеденненная в один шаг //
    printf("The sum of the first n terms of the sequence = %.3lf\n", get_sum_first_n(n));
    printf("The sum of all the members of the sequence, not less than a given number e = %.3lf\n", get_sum_dependet_e(n, e));

    return 0; 
}

int integer_input(void)
{ 
    int value = 0; 
    int result = scanf("%d", &value);
    if (result != 1) {
        errno = EIO;
        perror("Input error");
        exit(EXIT_FAILURE);
    }

    return value;
}

int positive_int(void)
{
     int value =  integer_input();
     
        if (value < 0)
    { 
        errno = EIO;
        perror("Impossible value for n");
        exit(EXIT_FAILURE);
    }

    return value;
}


double input(void)
{ 
    double parameter = 0.0;
    int outcome = scanf("%lf", &parameter);
    if (outcome != 1) { 
        errno = EIO; 
        perror("Input error\n");
        exit(EXIT_FAILURE);
    }

    return parameter;
}

double pozitiv_double(void)
{ 
    double parameter = input();
    if (parameter < DBL_EPSILON)
    { 
        errno = EIO;
        perror("Input error\n");
        exit(EXIT_FAILURE);
    }

    return parameter;
}

double next_term(const double previous_term, const int k) {
    return previous_term * (pow(k, 4) / k);
}

double get_sum_first_n(const int n)
{
    double sum = 0.0;
    double term = 1.0;  // Начальный член a_1 = 1^4 / 1!

    for (int k = 1; k < n; ++k) {
        term = next_term(term, k);
        sum += term;
    } 

    return sum;
}

double get_sum_dependet_e(const double e) 
{
    double sum = 0.0;
    double term = 1.0;  // Начальный член a_1 = 1^4 / 1!
    int k = 1;
    while (term >= e + DBL_EPSILON)
    {
        sum += term;
        k++;
        term = next_term(term, k);
    }
    
    return sum;
}
