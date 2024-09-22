#include <stdio.h> 
#include <math.h>

/*
* @brief proverka проверка на отрицательные числа
* @param x переменная x
* @param y переменная y
* return 1 в случае успеха(число > 0)
* return 0 в случае, если число отрицательное
*/
int proverka(double x, double y);

/*
 * @brief perimetr рассчитывает периметр
 * @param x переменная x
 * @param y переменная y
 * @return рассчитанное значение 
 */
double perimetr(double x, double y);

/*
 * @brief sqared рассчитывает площадь
 * @param x переменная x
 * @param y переменная y
 * return рассчитанное значение
 */
double sqared(double x, double y); 

/*
 * @brief diagonal рассчитывает диагональ
 * @param x переменная x
 * @param y переменная y
 * return рассчитанное значение
 */
double diagonal(double x, double y);

/*
 * @brief точка входа в программу
 * return 0 в случае успеха 
 */
int main(void)
{ 
    double x;
    double y;
    while(1)
    {
        printf("введите значение x и y: ");
        if (scanf("%lf %lf", &x, &y) != 2) {
            printf("Ошибка ввода. Пожалуйста, введите два числа.\n");
            while (getchar() != '\n');
                continue; 
        }
        
        if (proverka(x, y) == 1)
            break;
    }

    printf("perimetr - %.3lf\nsqared - %.3lf\ndiagonal - %.3lf\n", perimetr(x, y), sqared(x, y), diagonal(x, y));

    return 0; 
}

int proverka(double x, double y)
{ 
    if (x > 0 && y > 0) 
    {
        printf("проверка прошла успешно\n");
        return 1;
    }

    printf("введите числа >= 0\n");
    return 0;
}

double perimetr(double x, double y)
{ 
    return 2 * (x + y);
}

double sqared(double x, double y)
{ 
    return x * y;
}

double diagonal(double x, double y)
{ 
    return sqrt(pow(x, 2) + pow(y, 2));
}
