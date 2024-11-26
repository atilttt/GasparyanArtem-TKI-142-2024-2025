#include "function_for_4.2.h"

int main(void) {
    setlocale(LC_ALL, "Russian");
    printf("Введите размер массива\n");
    size_t n = pozitiv_input();
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
    print_replacement(array, n);

    printf("Введите произвольное целочисленное число k:\n");
    const int k = input();
    printf("Массив после добавления числа k:\n");\
    elementary_numbers(array, &n, k);

    printf("Создаем массив A на основе array.\n");
    int *A = array_from_array(array, n);
    printf("Массив A:\n");
    print_array(A, n);

    free(array);
    free(A);

    return 0;
}