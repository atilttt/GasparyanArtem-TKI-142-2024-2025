#include "function_for_4.2.h"

int main(void) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001); 



    printf("Введите размер массива\n");
    size_t n = pozitiv_input();
    int *array = create_array(n);

    printf("Выберите метод заполнения массива\n");
    printf("Метод 1 - заполнение рандомными числами, Метод 0 - заполнение с клавиатуры\n");
    int dependet = pozitiv_input();
    switch (dependet) {
        case INPUT_TYPE:
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
    int* new_array = create_array(n);
    new_array = replacement(array, n); 
    print_array(new_array, n); 
    free(new_array);

    printf("Введите произвольное целочисленное число k:\n");
    const int k = input();
    printf("Массив после добавления числа k:\n");\
    size_t counter = count_elementary(array, n);
    int *new_array_2 = create_resized_array(array, n, counter, k);
    print_array(new_array_2, n + counter);
    free(new_array_2);

    printf("Создаем массив A на основе array.\n");
    int *arr = array_from_array(array, n);
    printf("Массив A:\n");
    print_array(arr, n);

    free(array);
    free(arr);

    return 0;
}