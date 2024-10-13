#include <stdio.h>
#include <math.h>
#include <errno.h>  
#include <stdlib.h>

/**
 * @brief получает на вход число
 * @return возвращает проверенное число, в противном случае ошибку
 */
double input(void);

/**
 * @brief получает на вход число
 * @return возвращает провернное число, в противном случае ошибку 
 */
int Int_input(void);

/**
 * @brief функция для получения интеграла
 * @param number значение параметра number
 * @return полученный факториал
 */
unsigned long long factorial(int number);

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
    printf("Please enter value e:\n");
    const double e = input();
    printf("The sum of the first n terms of the sequence = %.3lf\n", get_sum_first_n(n));
    printf("The sum of all the members of the sequence, not less than a given number e = %.3lf\n", get_sum_dependet_e(n, e));

    return 0; 
}

int Int_input(void)
{ 
    int value = 0; 
    int result = scanf("%d", &value);
    if (result != 1 || result < 0) { 
        errno = EIO;
        perror("Input error");
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
        perror("Impossible value for e");
        exit(EXIT_FAILURE);
    }

    return parameter;
}

unsigned long long factorial(int number) {
    if (number == 0 || number == 1) {
        return 1;
    }
    unsigned long long fact = 1;
    for (int i = 2; i <= number; i++) {
        fact *= i;
    }

    return fact;
}

double get_sum_first_n(const int n)
{
    double sum = 0.0;
    for (int k = 1; k <= n; ++k) {  
        sum += pow(k, 4) / factorial(k);
    } 

    return sum;
}

double get_sum_dependet_e(int n, double e) {
    double sum = 0.0;
    for (int k = 1; k <= n; k++) {
        double now_sum = pow(k, 4) / factorial(k);
        if (now_sum >= e) {
            sum += now_sum;
        }
    }
    return sum;
}