#include <stdio.h> 
/*
* @brief расчитывает работу по формуле
* @param time константа time
* @param I переменная I - сила тока
* @param U переменная U - напряжение
* return возвращает рассчитанное значение
*/
double work(const int time, double I, double U);
/*
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void) 
{ 
    const int time = 1200.0;
    double I; 
    double U;
    scanf("%lf", &I);
    scanf("%lf", &U);
    printf("%lf", work(time, I, U));

    return 0;
}

double work(const int time, double I, double U)
{ 
    return U * I * time;
}