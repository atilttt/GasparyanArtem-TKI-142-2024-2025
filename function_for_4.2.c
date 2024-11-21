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
    check_pointer(array);
    return array;
}

int* copy_array(const int *array, const size_t n) {
    check_pointer(array);
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
    check_pointer(array);
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
    check_pointer(array);
    for (size_t i = 0; i < n; ++i) {
        printf("Введите элемент %zu:\n", i + 1);
        array[i] = input();
    }
}

void print_array(const int *array, const size_t n) {
    check_pointer(array);
    printf("Ваш массив:\n");
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void replacement(int *array, const size_t n) {
    check_pointer(array);
    for (size_t i = 0; i < n; ++i) {
        if (array[i] < 0) {
            array[i] = 0;
            break;
        }
    }
}

int* elementary_numbers(int *array, size_t *n, const int k) {
    check_pointer(array);
    size_t counter = 0;

    for (size_t i = 0; i < *n; ++i) {
        if (array[i] % (i + 1) == 0) {
            counter++;
        }
    }

    size_t new_size = *n + counter;
    int *new_array = create_array(new_size);

    size_t new_counter = 0;
    for (size_t i = 0; i < *n; ++i) {
        new_array[new_counter++] = array[i];
        if (array[i] % (i + 1) == 0) {
            new_array[new_counter++] = k;
        }
    }

    free(array);
    *n = new_size;
    return new_array;
}

int* array_from_array(const int *array, const size_t n) {
    check_pointer(array);
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