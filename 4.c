#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <math.h> 

/**
 * @brief получает на вход число из потока ввода
 * @return возвращает полученное числов, в случае, если число задано некорректно, завершает программу и выдает ошибку 
 */
int integer_input(void);

/**
 * @brief 
 * @return
 */
void pozitiv(const int n);

/**
 * @brief функция для проверки пользовательского выбора метода
 * @return возвращает ошибку в случае, если пользователь ввел некорректное значение
 */
void check_value_metod(const int metod);

int choose_metod(const int metod);
/**
 * @brief
 */
void get_arrey();


int main(void)
{ 
    printf("Please enter the number of elements in arrey\n");
    const int n = integer_input();
    pozitiv(n);
    printf("please enter the option to fill in the array. Enter the number: 1 or 2\n");
    int metod = integer_input();
    check_value_metod(metod);


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

void check_value_metod(const int metod)
{ 
    if (metod != 1 || metod != 2)
    { 
        errno = EINVAL;
        perror("the entered method value is incorrect\n");
        exit(EXIT_FAILURE);
    }
}