#include "function_for_4.2.h"

int input(void) {
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1) {
        perror("Ошибка ввода");
        exit(EXIT_FAILURE);
    }
    return value;
}

int pozitiv_input(void) {
    int value = input();
    if (value <= 0) {
        perror("Ошибка ввода: число должно быть > 0");
        exit(EXIT_FAILURE);
    }
    return value;
}

int* create_array(const size_t n) {
    int *array = (int *)malloc(n * sizeof(int));
    check_array(array);
    return array;
}

int* copy_array(const int *array, const size_t n) {
    int *new_array = create_array(n);
    for (size_t i = 0; i < n; ++i) {
        new_array[i] = array[i];
    }
    return new_array;
}

void check_array(const int *array) {
    if (array == NULL) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
}

void random_filling(int *array, const size_t n) {
    printf("Введите минимальное и максимальное значения:\n");
    int min = input();
    int max = input();
    if (min > max) {
        printf("Ошибка: минимальное значение больше максимального.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n; ++i) {
        array[i] = rand() % (max - min + 1) + min;
    }
}

void user_input_filling(int *array, const size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("Введите элемент %zu:\n", i + 1);
        array[i] = input();
    }
}

void print_array(const int *array, const size_t n) {
    printf("Ваш массив:\n{");
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    printf("}\n");
}

int* replacement(int *array, const size_t n) {

    int *array_2 = copy_array(array, n);
    for (size_t i = 0; i < n; ++i) {
        if (array_2[i] < 0) {
            array_2[i] = 0;
            break;
        }
    }

    return array_2;
}

void print_replacement(int *array, const size_t n)
{ 
    int* new_array = create_array(n);
    new_array = replacement(array, n); 
    print_array(new_array, n); 
    free(new_array);
}

void elementary_numbers(int *array, size_t *n, const int k) {
    size_t counter = 0; 
    for (size_t i = 0; i < *n; i++) { 
        if (array[i] % (i + 1) == 0) {
            ++counter;
        }
    }

    size_t new_n = *n + counter; 
    int *new_array = copy_array(array, new_n);

    size_t index = 0;
    for (size_t j = 0; j < *n; j++) { 
        new_array[index++] = array[j];
        if (array[j] % (j + 1) == 0) { 
            new_array[index++] = k;
        }
    }

    print_array(new_array, new_n);
    free(array);
}

int* array_from_array(const int *array, const size_t n) {
    int *A = create_array(n);

    for (size_t i = 0; i < n; ++i) {
        if ((i + 1) % 2 == 0) {
            A[i] = (i - 1) * array[i];
        } else {
            A[i] = array[i] * i * 2;
        }
    }
    return A;
}