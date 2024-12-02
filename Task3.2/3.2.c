#include <stdio.h>
#include <math.h>
#include <errno.h>  
#include <stdlib.h>
#include <float.h> 

/**
 * @brief получает на вход число из потока ввода
 * @return возвращает проверенное число, в противном случае завершает программу с ошибкой
 */
double input(void);

/**
 * @brief получает на вход целое число из потока ввода
 * @return возвращает проверенное целое число, в противном случае завершает программу с ошибкой
 */
int integer_input(void);

/**
 * @brief проверяет, что введенное число является положительным целым числом
 * @return возвращает положительное целое число, иначе завершает выполнение программы
 */
int positive_int(void);

/**
 * @brief проверяет, что введенное число является положительным (вещественное число)
 * @return возвращает положительное число, иначе завершает выполнение программы
 */
double positive_double(void);

/**
 * @brief вычисляет следующий член последовательности по формуле f(k) = -k^4 / k! (какая-то ошибка была)
 * @param k Текущий индекс последовательности
 * @return значение следующего члена последовательности
 */
double next_term(const int k);

/**
 * @brief рассчитывает сумму первых `n` членов последовательности
 * @param n Количество первых членов последовательности
 * @return сумма первых `n` членов
 */
double get_sum_first_n(const int n);

/**
 * @brief рассчитывает сумму всех членов последовательности, которые больше или равны заданного `e`
 * @param e Значение точности (ограничивающий член последовательности)
 * @return сумма членов, которые больше или равны `e`
 */
double get_sum_dependent_e(const double e);

/**
 * @brief Точка входа в программу
 * @return 0 в случае успешного выполнения
 */
int main(void) {
    printf("Please enter the number of sequence elements (n):\n");
    const int n = positive_int();
    printf("Please enter value e (precision):\n");
    const double e = positive_double();

    printf("The sum of the first n terms of the sequence: %.3lf\n", get_sum_first_n(n));
    printf("The sum of all the members of the sequence not less than e: %.3lf\n", get_sum_dependent_e(e));

    return 0; 
}

int integer_input(void) { 
    int value = 0; 
    int result = scanf("%d", &value);
    if (result != 1) {
        errno = EIO;
        perror("Input error");
        exit(EXIT_FAILURE);
    }

    return value;
}

int positive_int(void) {
    int value = integer_input();
    if (value <= 0) { 
        errno = EINVAL;
        perror("Value must be a positive integer");
        exit(EXIT_FAILURE);
    }

    return value;
}

double input(void) { 
    double parameter = 0.0;
    int outcome = scanf("%lf", &parameter);
    if (outcome != 1) { 
        errno = EIO; 
        perror("Input error");
        exit(EXIT_FAILURE);
    }

    return parameter;
}

double positive_double(void) { 
    double parameter = input();
    if (parameter <= DBL_EPSILON) { 
        errno = EINVAL;
        perror("Value must be a positive number");
        exit(EXIT_FAILURE);
    }

    return parameter;
}

/**
 * @brief Вычисление элемента последовательности по формуле: (-1)^k * (k^4 / k!)
 */
double next_term(const int k) {
    static double factorial = 1.0; // Рекуррентное вычисление факториала
    factorial *= (k == 0) ? 1.0 : k; // Если k == 0, то факториал остается 1
    return pow(-1, k) * (pow(k, 4) / factorial); // Элемент ряда: (-1)^k * (k^4 / k!)
}

/**
 * @brief Расчет суммы первых n членов последовательности
 */
double get_sum_first_n(const int n) {
    double sum = 0.0; 

    for (int k = 0; k < n; ++k) {
        sum += next_term(k); 
    } 

    return sum;
}

/**
 * @brief Расчет суммы членов ряда, модуль которых >= e
 */
double get_sum_dependent_e(const double e) {
    double sum = 0.0;
    double term = 0.0;  
    int k = 0;

    do {
        term = next_term(k); 
        if (fabs(term) >= e) {
            sum += term;
        }
        k++;
        } while (fabs(term) >= e);

    return sum;
}