#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/**
 * @brief определяет наши константы
 * @return возвращает их значения
 */
void determinant(void);

/**
 * @brief проверка получаемого значения
 * @return возвращает проверенное число
 */
double inputDoble(void);

/**
 * @brief проверка полученного значения
 * @return возвращает полученное значение
 */
int inputInt(void);

/**
 * @brief рассчитывает периметр прямоугольника
 * @param x значение ширины 
 * @param y значение длинны 
 * @return рассчитанное значение периметра
 */
double getPerimetr(double const  x, double const y);

/**
 * @brief рассчитывает площадь прямоугольника 
 * @param x значение ширины 
 * @param y значение длинны 
 * @return рассчитанное значения площади прямоугольника
 */
double getArea(double const x, double const y);

/**
 * @brief рассчитывает диагональ прямоугольника 
 * @param x значение ширины 
 * @param y значение длинны 
 * @return рассчитанное значение диагонали прямоугольника
 */
double getDiagonal(double const x, double const y);

/**
 * 
 */
enum request{perimetr, area, diagonal};

/**
 * @brief точка входа в программу
 * @return 0 в случае успехa
 */
int main(void)
{ 
    double const x = input();
    double const y = input();
    determinant();
    int re = inputInt();
    switch(re)
    { 
        case perimetr:
            printf("Периметр прямоугольника = %.2lf\n", getPerimetr(x, y));
            break;
        case area:
            printf("Площадь прямоугольника = %.2lf\n", getArea(x, y));
            break;
        case diagonal:
            printf("Диагональ прямоугольника = %.2lf\n", getDiagonal(x, y));
            break;
        default:
            errno = ERANGE;
            perror("Несуществующая функция\n");
            exit(EXIT_FAILURE);
    }

    return 0; 
}

void determinant(void)
{ 
    printf("Perimetr - %d\n", perimetr);
    printf("Area - %d\n", area);
    printf("Diagonal - %d\n", diagonal);
}

double inputDouble(void)
{
    double value = 0;
    int result= scanf("%lf", &value);
    if (result != 1)
    {
        errno = EIO;
        perror("Ошибка ввода\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

int inputInt(void)
{ 
    int c = 0;
    int check = scanf("%d", &c);
    if (check != 1)
    { 
        errno = EIO;
        perror("Ошибка ввода");
        exit(EXIT_FAILURE);
    }
    return c;
}

double getPerimetr(double const x, double const y)
{ 
    return 2 * (x + y);
}
double getArea(double const x, double const y)
{ 
    return x * y;
}
double getDiagonal(double const x, double const y)
{ 
    return sqrt(pow(x, 2) + pow(y, 2));
}
