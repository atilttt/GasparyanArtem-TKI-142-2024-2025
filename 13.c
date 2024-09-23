#include <stdio.h>
/*
 * @brief рассчитывает работу эл.тока по формуле
 * @param I - сила тока
 * @param U - напряжение
 * @param time - время переведенное в секунды 
 * return рассчитанное значение
 */
double getA(const double time, double I, double U);

/*
 * @brief считывает вещественное число
 * @return возвращает вещественное число
 */
double input();

/*
* @brief точка входу в прогамму
* return 0 в случае успехa
*/
int main()
{ 
    const double time = 20.0; 
    puts("Введите значение силы тока");
    double I = input(); 
    puts("Введите значение напряжения");
    double U = input(); 
    printf("%lf", getA(time, I, U));

    return 0;
}

double getA(const double time, double I, double U)
{
    return U * I * (time * 60);
}

double input() 
{ 
    double value = 0.0;
    int result = scanf("%lf", &value);
    if (result != 2)
    {
        perror("Invalid input!");
    }
    return value;
}