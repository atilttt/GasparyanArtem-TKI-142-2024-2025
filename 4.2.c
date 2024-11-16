#include "4.2.h"

int main(void)
{ 
    printf("Введите размер массива\n");
    size_t n = pozitiv_input();
    int *array = (int*)malloc(n * sizeof(int));
    printf("Выберите метод заполнения массива\n");
    printf("Метод 1 - заполнение рандомными числами, Метод 0 - заполнение с клавиатуры\n");
    int dependet = pozitiv_input();
    switch (dependet)
    { 
        case RANDOM: 
            random_filling(array, n);
            break;
        case INPUT:

            break;
    }

    return 0;
}

int input(void)
{ 
    int value = 0; 
    int result = scanf("%d", &value);
    if (result != 1)
    { 
        errno = EIO;
        exit(EXIT_FAILURE);
    }
    
    return value;
}

int pozitiv_input(void)
{ 
    int value = input();
    if (value < 0)
    { 
        errno = EIO;
        exit(EXIT_FAILURE);
    } 
    
    return value;
}

void random_filling(int *array, const size_t n)
{ 
    for (int i = 0; i < n; ++i)
    { 
        array[i] = (rand() % n);
    }
}

void user_input_filling(int *array, const size_t n)
{ 
    for (int i = 0; i < n; ++i)
    { 
        array[i] = input();
    }
}