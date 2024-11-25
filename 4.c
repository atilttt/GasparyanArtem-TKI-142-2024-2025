#include "4.h"

int main(void) {
    printf("Введите размер массива\n");
    const size_t n = (size_t)pozitiv_input();
    int* array = create_array(n);

    printf("Выберите метод заполнения массива.\n");
    printf("0 - ручной ввод, 1 - случайное заполнение\n");
    int dependet = pozitiv_input();
    switch (dependet) {
        case INPUT:
            user_input(array, n);
            break;
        case RANDOM:
            random_filling(array, n);
            break;
        default:
            printf("Неверный ввод.\n");
            free(array);
            exit(EXIT_FAILURE);
    }

    print_array(array, n);

    printf("Введите количество последних элементов (k), которые нужно изменить на противоположные:\n");
    const int k = pozitiv_input();
    int* array2 = check_elements_k(array, k, n);
    print_array(array2, n);
    free(array2);

    printf("Элементы массива, кратные 3:\n");
    index_elements_multiples_three(array, n);

    printf("Введите произвольное число K для проверки парных элементов:\n");
    const int number = input();
    sum_paired_elements(array, n, number);

    free(array);
    return 0;
}

int input(void) {
    int value;
    if (scanf("%d", &value) != 1) {
        perror("Ошибка ввода");
        exit(EXIT_FAILURE);
    }
    return value;
}

int pozitiv_input(void) {
    int value = input();
    if (value <= 0) {
        perror("Ошибка: введено некорректное число (должно быть > 0)");
        exit(EXIT_FAILURE);
    }
    return value;
}

int* create_array(const size_t n) {
    int* array = (int*)malloc(n * sizeof(int));
    check_array(array);
    return array;
}

void random_filling(int *array, const size_t n) {
    check_array(array);

    printf("Введите минимальное и максимальное значение:\n");
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

void user_input(int *array, const size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("Введите %zu-й элемент:\n", i + 1);
        array[i] = input();
    }
}

void print_array(const int *array, const size_t n) {
    printf("Ваш массив: [");
    for (size_t i = 0; i < n; ++i) {
        printf("%d%s", array[i], (i < n - 1) ? ", " : "]\n");
    }
}

void check_array(const int *array) {
    if (!array) {
        perror("Ошибка: массив не выделен");
        exit(EXIT_FAILURE);
    }
}

int* copy_array(const int *array, const size_t n) {
    int* new_array = (int*)malloc(n * sizeof(int));
    check_array(new_array);

    for (size_t i = 0; i < n; ++i) {
        new_array[i] = array[i];
    }
    return new_array;
}

int* check_elements_k(const int *array, int k, const size_t n) {
    if (k <= 0 || k > (int)n) {
        printf("Ошибка: k должно быть в диапазоне 1 <= k <= %zu\n", n);
        exit(EXIT_FAILURE);
    }

    int* array_2 = copy_array(array, n);

    for (size_t i = n - k; i < n; ++i) {
        array_2[i] = -array_2[i];
    }

    return array_2;
}

void index_elements_multiples_three(const int *array, const size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (array[i] % 3 == 0) {
            printf("Индекс: %zu, значение: %d\n", i, array[i]);
        }
    }
}

void sum_paired_elements(const int *array, const size_t n, const int number) {
    size_t count = 0;

    for (size_t i = 0; i < n - 1; ++i) {
        if (array[i] + array[i + 1] == number) {
            count++;
        }
    }

    printf("Найдено %zu пар, сумма которых равна %d\n", count, number);
}