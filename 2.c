#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * @brief проверка получаемого значения
 * @return возвращает проверенное число
 */
double input();

/**
 * @brief рассчитывает периметр прямоугольника
 * @param x значение ширины 
 * @param y значение длинны 
 * @return рассчитанное значение периметра
 */
double getA(double const  x, double const y);

/**
 * @brief рассчитывает площадь прямоугольника 
 * @param x значение ширины 
 * @param y значение длинны 
 * @return рассчитанное значения площади прямоугольника
 */
double getB(double const x, double const y);

/**
 * @brief рассчитывает диагональ прямоугольника 
 * @param x значение ширины 
 * @param y значение длинны 
 * @return рассчитанное значение диагонали прямоугольника
 */
double getC(double const x, double consty);

enum request{perimetr, area, diagonal};
/**
 * @brief точка входа в программу
 * @return 0 в случае успехa
 */
int main(void)
{ 
    double const x = input();
    double const y = input();
    int re;
    printf("Выберите операцию, 0 - периметр, 1 - площадь, 2 - диагональ\n");
    if (scanf("%d", &re) != 1 || re < 0 || re > 2)
    { 
        printf("Несуществующий выбор операции");
        return 1;
    }

    switch(re)
    { 
        case perimetr:
            printf("Периметр прямоугольника = %.2lf\n", getA(x, y));
            break;

        case area:
            printf("Площадь прямоугольника = %.2lf\n", getB(x, y));
            break;

        case diagonal:
            printf("Диагональ прямоугольника = %.2lf\n", getC(x, y));
            break;

        default:
            printf("Неверный выбор операции\n");
            break;

    }

    return 0; 
}

double input()
{
    double value;
    int result= scanf("%lf", &value);
    if (result != 1)
    {
        perror("Ошибка ввода\n");
        abort();
    }
    return value;
}

double getA(double const x, double const y)
{ 
    return 2 * (x + y);
}

double getB(double const x, double const y)
{ 
    return x * y;
}

double getC(double const x, double const y)
{ 
    return sqrt(pow(x, 2) + pow(y, 2));
}