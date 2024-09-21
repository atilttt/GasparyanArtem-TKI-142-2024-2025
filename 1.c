#include <stdio.h> 
#include <math.h> 
/* @brief рассчитывает выражение A по формуле 
 * @param x значение константы x
 * @param y значение константы y
 * @param z значение константы z
 * @return рассчитанное значение
 */
double getA(const double x, const double y, const double z);
/* @brief рассчитывает выражение B по формуле
 * @param x значение константы x
 * @param y значение константы y
 * @param z значение константы z
 * @return рассчитанное значение.
 */
double getB(const double x, const double y, const double z);
/* @brief Точка входа в программу
 * @return 0 в случае успеха
 */
int main()
{
    const double x = -2.9;
    const double y = 15.5;
    const double z = 1.5;
    printf("%lf\n%lf", getA(x, y, z), getB(x, y, z));

    return 0;
}

double getA(const double x, const double y, const double z)
{
    return sqrt(pow(x, 2) + y) - pow(y, 2)*pow(sin((x + z) / x), 3);
}

double getB(const double x, const double y, const double z)
{ 
    return pow(cos(pow(x, 3)), 2) - (x / (sqrt(pow(z, 2) + pow(y, 2))));
}