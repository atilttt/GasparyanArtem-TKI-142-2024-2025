#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/**
 * @brief функия, получающая значение из потока ввода
 * @return возвращает оишбку, в случае если значение некорректное.
 */
int input(void);


/**
 * @brief перевод значения веса в граммах в унции
 * @param inch значение 1 унция
 * @param x вес в граммах
 * @return возвращает рассчитаное значение
 */
double result(double x);

/**
 * @brief вход в программу
 * @return 0 в случае успеха
 */
int main(void) 
{ 
    double x;
    printf("Введите вес в граммах:");
    scanf("%lf", &x);
    printf("%lf", result(x));

    return 0;
}

int input(void)
{ 
    double value = 0.0;
    int result = scanf("%lf", &value);
    if (result != 1)
    { 
        errno = EIO;
        perror("Input value is discorrect\n");
        exit(EXIT_FAILURE);
    }

    return value;
}

double result(double x)
{
    const double unz = 28.3; 
    return x / unz;
}