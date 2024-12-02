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

size_t count_elementary(const int *array, size_t n) {
    size_t counter = 0;
    for (size_t i = 0; i < n; i++) {
        if (array[i] % (i + 1) == 0) {
            ++counter;
        }
    }
    return counter;
}

int* create_resized_array(const int *array, const size_t n, const size_t counter, const int k) {
    size_t new_n = n + counter;
    int *new_array = create_array(new_n);

    size_t index = 0;
    for (size_t i = 0; i < n; i++) {
        new_array[index++] = array[i];
        if (array[i] % (i + 1) == 0) {
            new_array[index++] = k;
        }
    }
    return new_array;
}

int* array_from_array(const int *array, const size_t n) {
    int *arr = create_array(n);

    for (size_t i = 0; i < n; ++i) {
        if ((i + 1) % 2 == 0) {
            arr[i] = (i - 1) * array[i];
        } else {
            arr[i] = array[i] * i * 2;
        }
    }
    return arr;
}