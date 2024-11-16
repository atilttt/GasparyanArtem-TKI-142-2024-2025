#include <stdio.h> 
#include <errno.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>


/**
 * @brief функция проверяет пользовательский ввод
 * @return возвращает ошибку в случае, если пользователь ввел некоректное значение
 */
int input(void);

/**
 * @brief функция проверяет ввел ли пользователь положительное число
 * @return возвращает ошибку в случае, если число отрицательное
 */
int pozitiv_input(void);

/**
 * @param RANDOM заполнение рандомными числами
 * @param INPUT заполнение пользователем
 */
enum choice { 
    RANDOM = 1, 
    INPUT = 0
};

/**
 * @brief функция, выполняющая заполнение массива рандомными числами
 * @param array указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 */
void random_filling(int *array, const size_t n);

/**
 * @brief функция, выполняюзая заполнение массива с помощью пользовательского ввода
 * @param array указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 */
void user_input_filling(int *array, const size_t n);

/**
 * @brief функция, которая выводит массив
 * @param array указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 */
void print_array(const int *array, const size_t n);

/**
 * @brief функция находит первый отрицательный элемент в массиве и меняет его на 0
 * @param array указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 */
void replacement(int *array, const size_t n);

/**
 * @brief функция находит элементарные числа и после них вставляет произвольное число, заданое пользователем
 * @param array указатель на массив (эквиваленто array[]) 
 * @param n переменная, отвечающая за размер массива 
 * @param k переменная, хранящая в себе произвольное число, заданное пользователем
 */
int* elementary_numbers(int *array, const size_t n, const int k);

/**
 * @brief функция релизует массив А на основе массива array
 * @param указатель на массив (эквивалентно array[]) 
 * @param n переменная, отвечающая за размер массива
 */
void array_from_array(const int *array, const size_t n);