#ifndef FUNCTION_FOR_4_3_H

#define FUNCTION_FOR_4_3_H

#include <stdio.h> 
#include <stdlib.h>
#include <errno.h>
#include <time.h>

/**
 * @brief функция, проверяющая корректность ввода значения
 * @return вернет ошибку и закроет программу, если значение является некорректным
 */
int input(void);

/**
 * @brief функция проверяет значение на положительность
 * @return вернет ошибку и закроет программу, если пользователь ввел отрицательное значение
 */
int pozitiv_input(void);

/**
 * @param input заполнение вводом с клавиатуры
 * @param random заполнение рандомными числами
 */
enum choice{INPUT = 0, RANDOM = 1};

/**
 * @brief функция отвечающая за создание массива
 * @param n переменная, отвечающая за кол-во строк в массиве
 * @param m переменная, отвечающая за кол-во столбцов в массиве
 */
int** create_array(const size_t n, const size_t m);

/**
 * @brief функция, отвечающая за проверку адреса
 * @return в случае если адрес = 0, вернет ошибку
 */
void check_array(int **array);

/**
 * @brief фунцкия, печатающая массив
 */
void print_array(int **array, const size_t n, const size_t m);

/**
 * @brief функция, копирующая исходный массив
 * @param *array
 * @param n переменная, отвечающая за кол-во строк массива
 * @param m переменная, овтечаюзая за кол-во столбцов массива
 */
int **copy_array(int **array, const size_t n, const size_t m);
/**
 * @brief функия очситки массива
 * @param **array указатель на массив
 * @param n переменная, отвечающая за кол-во строк массива
 * @param m переменная, отвечающая за кол-во столбцов массива
 */
void clear_array(int **array, const size_t n, const size_t m);


/**
 * @brief функция, заполняющая массив рандомными числами
 * @param **array указатель на массив
 * @param n переменная, отвечающая за кол-во строк в массиве
 * @param m переменная, отвечающая за кол-во столбцов в массиве
 */
void random_filling(int **array, const size_t n, const size_t m);

/**
 * @brief функция, заполняющая массив пользовательским вводом
 * @param **array указатель на массив
 * @param n переменная, отвечающая за кол-во строк в массиве
 * @param m переменная, отвечающая за кол-во столбцов в массиве
 */
void input_filling(int **array, const size_t n, const size_t m);

/**
 * @brief функция, меняющая максимальный элемент в строке на противоположный
 * @param *array указатель на массив
 * @param n переменная, отвечаюзая за кол-во строк в массиве
 * @param m переменная, отвечающая за кол-во столбцов в массиве
 * @return измененный массив
 */
int** replace(int **array, const size_t n, const size_t m);

/**
 * @brief функция, которая ищет максимальный элемент массива
 * @param **array указатель на массив 
 * @param n переменная, отвечающая за кол-во строк в массиве 
 * @param m переменная, отвечающая за кол-во столбцов в массиве
 * @return возвращает максимальный элемент
 */
int max_element_from_array(int **array, const size_t n, const size_t m);

/**
 * @brief функция-счетчик, ищет максимальный элемент в столбце
 * @param **array указатель на массив
 * @param n переменная, отвечающая за кол-во строк в массиве
 * @param m переменная, отвечающая за кол-во столбцов в массиве
 * @return возвращает кол-во таких элементов
 */
int counter(int **array, const size_t n, const size_t m);

/**
 * @brief функция, вставляющая столбец из нулей после каждого столбца, содержащего максимальный элемент
 * @param **array указатель на массив
 * @param n перменная, отвечающая за кол-во строк в массиве
 * @param m переменная, отвечающая за кол-во столбцов в массиве
 * @return возвращает массив с добавлеными столбцами
 */
int **array_with_column_from_zeros(int **array, const size_t n, const size_t m);

#endif //FUNCTION_FOR_4_3_H