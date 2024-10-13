#include <stdio.h>
#include <math.h>
#include <errno.h>  
#include <stdlib.h>

/**
 * 
 */
double input(void);
int Int_input(void);
unsigned long long factorial(int number);
double get_sum_first_n(int n);
double get_sum_dependet_e(int n, const double e);

int main(void)
{
    printf("Please enter the number of sequence elements:\n");
    const int n = Int_input();
    printf("Please enter value e:\n");
    const double e = input();
    printf("The sum of the first n terms of the sequence = %.3lf\n", get_sum_first_n(n));
    printf("The sum of all the members of the sequence, not less than a given number e = %.3lf\n", get_sum_dependet_e(n, e));

    return 0; 
}

int Int_input(void)
{ 
    int value = 0; 
    int result = scanf("%d", &value);
    if (result != 1 || result < 0) { 
        errno = EIO;
        perror("Input error");
        exit(EXIT_FAILURE);
    }

    return value;
}

double input(void)
{ 
    double parameter = 0.0;
    int outcome = scanf("%lf", &parameter);
    if (outcome != 1) { 
        errno = EIO; 
        perror("Impossible value for e");
        exit(EXIT_FAILURE);
    }

    return parameter;
}

unsigned long long factorial(int number) {
    if (number == 0 || number == 1) {
        return 1;
    }
    unsigned long long fact = 1;
    for (int i = 2; i <= number; i++) {
        fact *= i;
    }

    return fact;
}

double get_sum_first_n(const int n)
{
    double sum = 0.0;
    for (int k = 1; k <= n; ++k) {  
        sum += pow(k, 4) / factorial(k);
    } 

    return sum;
}

double get_sum_dependet_e(int n, double e) {
    double sum = 0.0;
    for (int k = 1; k <= n; k++) {
        double now_sum = pow(k, 4) / factorial(k);
        if (now_sum >= e) {
            sum += now_sum;
        }
    }
    return sum;
}
