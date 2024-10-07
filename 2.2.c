#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 

double input(); 
double getA(const double x);
double getB(const double x);

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
        perror("Ошибка ввода\n");
        abort();
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