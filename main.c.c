#include "function_for_4.2.h"
#include "function_for_4.2.c"

int main(void) {
    printf("Введите размер массива\n");
    const size_t n = pozitiv_input();
    int *array = create_array(n);

    printf("Выберите метод заполнения массива\n");
    printf("Метод 1 - заполнение рандомными числами, Метод 0 - заполнение с клавиатуры\n");
    int dependet = pozitiv_input();
    switch (dependet) {
        case INPUT:
            user_input_filling(array, n);
            break;
        case RANDOM:
            random_filling(array, n);
            break;
        default:
            printf("Произошла ошибка: некорректный ввод.\n");
            free(array);
            exit(EXIT_FAILURE);
    }
    print_array(array, n);

    printf("Первый отрицательный элемент будет заменен на ноль.\n");
    replacement(array, n);
    print_array(array, n);

    printf("Введите произвольное целочисленное число k:\n");
    const int k = input();
    array = elementary_numbers(array, (size_t *)&n, k);
    printf("Массив после добавления числа k:\n");
    print_array(array, n);

    printf("Создаем массив A на основе array.\n");
    int *A = array_from_array(array, n);
    printf("Массив A:\n");
    print_array(A, n);

    free(array);
    free(A);

    return 0;
}