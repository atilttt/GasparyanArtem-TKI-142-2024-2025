#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <math.h>
#include <time.h> 

/**
 * @brief получает на вход число из потока ввода
 * @return возвращает полученное числов, в случае, если число задано некорректно, завершает программу и выдает ошибку 
 */
int integer_input(void);

/**
 * @brief проверка значения на положительность
 * @param n значение параметра n
 * @return возвращает ошибку в случае если значение заданно некорректно
 */
void pozitiv(const int n);

/**
 * @param random заполнение массива случайными числами
 * @param kaybord_input заполнение массива вводом с клавиатуры
 */
enum choiсe{random = 1, keyboard_input = 2};

int main(void)
{ 
    printf("Please enter the number of elements in arrey\n");
    const int n = integer_input();
    pozitiv(n);
    int arr[n]; 
    switch

}

int integer_input(void)
{ 
    int value = 0; 
    int result = scanf("%d", &value);
    if (result != 1)
    { 
        errno = EIO;
        perror("input error\n");
        exit(EXIT_FAILURE);
    }
    
    return value;
}

void pozitiv(const int n)
{ 
    if (n < 0 || n == 0) 
    { 
        errno = EINVAL; 
        perror("the number of elements cannot be negative\n");
        exit(EXIT_FAILURE);
    }
}

