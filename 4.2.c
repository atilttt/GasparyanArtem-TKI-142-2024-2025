#include "4.2.h"

int main(void)
{ 
    printf("Введите размер массива\n");
    size_t n = pozitiv_input();
    int *array = (int*)malloc(n * sizeof(int));
    if (array == NULL)
    { 
        printf("Произошла ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    printf("Выберите метод заполнения массива\n");
    printf("Метод 1 - заполнение рандомными числами, Метод 0 - заполнение с клавиатуры\n");
    int dependet = pozitiv_input();
    switch (dependet)
    { 
        case INPUT:
            user_input_filling(array, n);
            break;
        case RANDOM: 
            random_filling(array, n);
            break;
        default:
            printf("Произошла ошибка, скорее всего вы ввели некорректное число:)\n");
            exit(EXIT_FAILURE);
    }
    print_array(array, n);

    printf("Первый встретившийся отрицательный элемент был заменен на ноль\n");
    replacement(array, n);

    printf("Введите произвольное целочисленное число k\n");
    const int k = input();
    array = elementary_numbers(array, &n, k); 
    printf("Ваш массив с числом k\n");
    print_array(array, n);


    printf("Создадим массив A на основе array\n");
    array_from_array(array, n);
    printf("Ваш массив А\n");
    print_array(array, n);

    free(array); 
    return 0;
}

int input(void)
{ 
    int value = 0; 
    int result = scanf("%d", &value);
    if (result != 1)
    { 
        errno = EIO;
        printf("Ошибка ввода\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

int pozitiv_input(void)
{ 
    int value = input();
    if (value < 0)
    { 
        errno = EINVAL;
        printf("Ошибка ввода\n");
        exit(EXIT_FAILURE);
    } 
    return value;
}

void random_filling(int *array, const size_t n)
{ 
    for (size_t i = 0; i < n; ++i)
    { 
        array[i] = (rand() % n); 
    }
}

void user_input_filling(int *array, const size_t n)
{ 
    for (size_t i = 0; i < n; ++i)
    { 
        array[i] = input();
    }
}

void print_array(const int *array, const size_t n)
{ 
    for (size_t i = 0; i < n; ++i)
    { 
        printf("Ваш массив array: %d\n", array[i]);
    }
}

void replacement(int *array, const size_t n)
{ 
    for (size_t i = 0; i < n; ++i)
    {
        if (array[i] < 0)
        { 
            array[i] = 0;
            printf("Первый отрицательный элемент был заменен на ноль: %d\n", array[i]);
            break;
        }
    }
}

int* elementary_numbers(int *array, size_t *n, const int k)
{ 
   size_t counter = 0;
    for (size_t i = 1; i < *n; ++i) {
        if (array[i] % i == 0) {
            counter++;
        }
    }

    size_t new_size = *n + counter;
    int* new_array = (int*)malloc(new_size * sizeof(int));
    if (new_array == NULL)
    { 
        printf("Произошла ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    size_t new_counter = 0;
    new_array[new_counter++] = array[0];

    for (size_t i = 1; i < *n; ++i) {
        new_array[new_counter++] = array[i];
        if (array[i] % i == 0) {
            new_array[new_counter++] = k;
        }
    }

    free(array);
    array = new_array;
    *n = new_size;          
    return array;
}

void array_from_array(const int *array, const size_t n)
{ 
    int *A = (int*)malloc(n * sizeof(int));
    if (A == NULL)
    { 
        printf("Произошла ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n; ++i)
    { 
        if ((i + 1) % 2 == 0)
        {
            A[i] = (i - 1) * array[i];
        }
        else
        { 
            A[i] = array[i] * i * 2;
        }
    }
    
    free(A);    
}