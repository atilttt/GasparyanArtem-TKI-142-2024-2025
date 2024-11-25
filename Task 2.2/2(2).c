#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <errno.h>

/** 
 * @brief проверка введенного значения
 * @return возвращает значение
 */
double input(); 

/**
 * @brief рассчитывает значение функции по формуле
 * @param x значение переменной x
 * @return возвращает рассчитанное значение функции, при x < 2
 */
double getA(const double x);

/**
 * @brief рассчитывает значение функции по формуле
 * @param x значение переменной x
 * @return возвращает рассчитанное значение фукнции, при x >= 2
 */
double getB(const double x);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха 
 */
int main() 
{ 
    const double x = input();
    if (x < 2) 
    { 
        printf("функция равна = %.2lf", getA(x));
    }
    else
    { 
        printf("функция равна = %.2lf", getB(x));
    }

    return 0;
}

double input() 
{ 
    double value; 
    int result = scanf("%lf", &value);
    if (result != 1)
    {
        errno = EIO;
        perror("Ошибка ввода\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

double getA(const double x)
{ 
    return 1.5 * pow(cos(x), 2);
}

double getB(const double x)
{ 
    return pow(x - 2, 2) + 6;
}