#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <errno.h>
#include <time.h>

/**
 * @brief функция, выполняющая проверку введенного пользователем числа
 * @return ошибку в случае, если пользователь ввел не число или ввел не одно значение
 */
int input(void);

/**
 * @brief функция, выполняющая проверку на положительное число
 * @return ошибку в случае, если пользователь ввел отрицательное число
 */
int pozitiv_input(void);

/**
 * @param RANDOM отвечает за рандомнное заполнение массива
 * @param INPUT отвечате за заполнение массива из потока ввода
 */
enum choice{ 
    RANDOM = 1, INPUT = 0
};

/**
 * @brief заполняет массив рандомными числами
 * @param array - указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 */
void random_filling(size_t *array, const size_t n);

/**
 * @brief заполняет массив пользовательским вводом
 * @param array - указатель на массив (эквивалентно array[])
 * @param n перемнная, отвечающая за размер массива
 */
void user_input(size_t *array, const size_t n);

/**
 * @brief функция которая печатает массив
 * @param array указатель на массив (эквивалентно array []) 
 * @param n перменная, отвечающая за размер массива
 */
void print_array(const size_t *array, const size_t n);

/**
 * @brief заменяет последние k элементов массива на противоположные
 * @param array - указатель на массив (эквиваленто array[])
 * @param k переменная k
 * @param n переменная, отвечающая за размер массива
 */
void check_elements_k(size_t *array, const int k, const size_t n);

/**
 * @brief функция находит элементы, кратные 3ом, и выводит их
 * @param array указатель на массив (эквивалентно array[]) 
 * @param n переменная, отвечающая за размер массива
 */
void index_elements_multiples_three(const size_t *array, const size_t n);