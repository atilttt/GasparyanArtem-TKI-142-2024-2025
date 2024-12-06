#include <stdio.h>
#include <math.h> 
#include <stdlib.h> 
#include <errno.h> 


/**
 * @brief получает на вход число из потока ввода
 * @return возвращает введенное число
 */
double Input(void);

/**
 * @brief рассчитывает время, за которое путник одолел первую половину пути, где сделал привал
 * @param t1 v1 - время и скорость на первом участке
 * @param t2 v2 - время и скорость на втором участке
 * @param t3 v2 - время и скорость на третьем участке
 * @return возвращает рассчитанное значение времени
 */
double Path(const double t1, const double t2, const double t3, const double v1, const double v2, const double v3);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main() 
{
    printf("Введите значение времени и скорости на 1-ом участке\n"); 
    const double v1 = Input();
    const double t1 = Input();
    printf("Введите значение времени и скорости на 2-ом участке\n");
    const double v2 = Input();
    const double t2 = Input();
    printf("Введите значение времени и скорости на 3-eм участке\n");
    const double v3 = Input();
    const double t3 = Input();
    printf("Время до привала %.3lf", Path(t1,t2,t3,v1,v2,v3));

    return 0;
}

double Input(void)
{ 
    double value = 0.0; 
    int result = scanf("%lf", &value);
    if (result != 1 || value < 0)
    { 
        errno = EIO; 
        perror("Input error");
        exit(EXIT_FAILURE);
    }
    return value;
}

double Path(const double t1, const double t2, const double t3, const double v1, const double v2, const double v3)
{ 
    double s1 = t1 * v1; //расстояние первого участка//
    double s2 = t2 * v2; //расстояние второго участка//
    double s3 = t3 * v3; //расстояние третьего участкого//

    double total_path = s1 + s2 + s3; 
    double half_path = total_path / 2; 

    if (half_path < s1)
    { 
        return half_path / v1; //если путник находится на первом участке// 
    }

    half_path = half_path - s1;
    if (half_path < s2)
    { 
        return t1 + (half_path / v2);  //если путник находится на втором участке//
    }

    half_path = half_path - s2;
    if (half_path < s3)
    { 
        return t1 + t2 + (half_path / v3); //если путник находится на третьем участке//
    }

    return t1 + t2 + t3;
}