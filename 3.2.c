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
int Integer_input(void);

/**
 * @brief функция для проверки на положительность заданного параметра
 * @return возвращает ошибку в случае, если значение параметра заданно некорректно
 */
void check_n(const int n);
/**
 * @brief вычисляет следующий член последовательности при помощи рекуррентного выражения
 * @param previous_term значение предыдущего члена последовательности
 * @param k текущий индекс последовательности
 * @return значение следующего члена последовательности
 */
double next_term(const double previous_term, int k);

/**
 * @brief рассчитывает значение суммы первых n-членов последовательности
 * @param n кол-во элементов последовательности
 * @return рассчитанное значение суммы
 */
double get_sum_first_n(int n);

/**
 * @brief рассчитывает значение суммы всех членов последовательности, не меньше заданного числа е
 * @param n кол-во элементов последовательности
 * @param e значение заданного числа е
 * @return рассчитанное значение суммы
 */
double get_sum_dependet_e(int n, const double e);

/**
 * @brief точка входа в программу 
 * @return 0 в случае успеха
 */
int main(void)
{
    printf("Please enter the number of sequence elements:\n");
    const int n = Int_input();
    check_n(n);
    printf("Please enter value e:\n");
    const double e = input();
    printf("The sum of the first n terms of the sequence = %.3lf\n", get_sum_first_n(n));
    printf("The sum of all the members of the sequence, not less than a given number e = %.3lf\n", get_sum_dependet_e(n, e));

    return 0; 
}

int Integer_input(void)
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

void check_n(const int n)
{ 
    if (n < 0)
    { 
        errno = EINVAL; 
        perror("Impossible value for n");
        exit(EXIT_FAILURE);
    }
}

double input(void)
{ 
    double parameter = 0.0;
    int outcome = scanf("%lf", &parameter);
    if (outcome != 1) { 
        errno = EIO; 
        perror("Impossible value for e");
        exit(EXIT_FAILURE);
    }

    return parameter;
}

double next_term(const double previous_term, int k) {
    return previous_term * (pow(k, 4) / k);
}

double get_sum_first_n(const int n)
{
    double sum = 0.0;
    double term = 1.0;  // Начальный член a_1 = 1^4 / 1!

    for (int k = 1; k <= n; ++k) {
        if (k > 1) {
            term = next_term(term, k);
        }
        sum += term;
    } 

    return sum;
}

double get_sum_dependet_e(const double e) {
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