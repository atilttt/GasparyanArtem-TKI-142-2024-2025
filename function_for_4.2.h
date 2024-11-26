#ifndef FUNCTION_FOR_4_2_H

#define FUNCTION_FOR_4_2_H

#include <stdio.h> 
#include <errno.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include <locale.h>
#include <windows.h>  


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
 * @brief функция, создающая массив
 * @param n переменная, отвечающая за размер массива
 * @return созданный массив
 */
int* create_array(const size_t n);

/**
 * @brief функция, копирающая массив 
 * @param *array указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 * @return скопированный массив
 */
int* copy_array(const int *array, const size_t n);

/**
 * @brief функция проверяющая значение адресса
 * @param *array - указатель на массив (эквивалентно array[])
 */
void check_array(const int *array);

/**
 * @param INPUT заполнение пользователем
 * @param RANDOM заполнение рандомными числами
 */
enum choice { 
    INPUT_TYPE = 0, 
    RANDOM = 1
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
 * @brief функция создает новый массив на основе прошлого 
 * @param arrey указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 */
int* copy_array(const int *array, const size_t n);

/**
 * @brief функция находит первый отрицательный элемент в массиве и меняет его на 0
 * @param array указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 */
int* replacement(int *array, const size_t n);

/**
 * @brief функция выводит новый массив, в котором первый отрицательный элемент заменен на ноль
 * @param *array указатель на массив (эквивалентно array[]) 
 * @param n переменная, отвечающая за размер массива
 */
void print_replacement(int *array, const size_t n);

/** 
 * @brief считает элементы массива, которые кратны своему номеру
 * @param *array указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 * @return возвращает кол-во таких элементов
 */
size_t count_elementary(const int *array, size_t n);

/**
 * @brief функция вставляет элемент k, после каждого элемента массива, кратного своему номеру
 * @param *array указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 * @param counter переменная-счетчик (хранит в себе кол-во элементов, кратных своему номеру)
 * @param k переменная, хранящая в себе произвольное значение, введенное пользователем, которое вставляется после каждого элемента, кратного своему номеру
 * @return массив с вставленным в него числом K
 */
int* create_resized_array(const int *array, const size_t n, const size_t counter, const int k);

/**
 * @brief функция, которая ввыводит массив с числом K
 * @param *array указатель на массив
 * @param n переменная, отвечающая за размер массива
 * @param k произвольное значение введенное пользователем
 */
void print_elementary_numbers(int *array, const size_t n, const int k);

/**
 * @brief функция релизует массив А на основе массива array
 * @param указатель на массив (эквивалентно array[]) 
 * @param n переменная, отвечающая за размер массива
 */
int* array_from_array(const int *array, const size_t n);


#endif // FUNCTION_FOR_4_2_H