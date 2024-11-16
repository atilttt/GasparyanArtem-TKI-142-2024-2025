#include "4.h"

int main(void)
{ 
    printf("Введите размер массива\n");
    const size_t n = pozitiv_input();
    size_t* array = (size_t*)malloc(n * sizeof(size_t));
    if (array == NULL)
    { 
        printf("Произошла ошибка\n");
        abort();
    }
    
    printf("Пожалуйста, выберите каким методом вы хотите воспользоваться.\n");
    printf("Метод рандомного заполнения - 1, метод заполнения с помощью ввода - 0\n");
    int dependet = pozitiv_input();
    switch(dependet)
    { 
        case RANDOM:
            random_filling(array, n);
            break;
        case INPUT:
            user_input(array, n);
            break;
        default:
            printf("Вы где-то ошиблись, скорее всего это неверный ввод\n");
            exit(EXIT_FAILURE);
    }
    print_array(array, n);
    printf("Вы можете заменить последние k элементов на противоположные по знаку\n");
    printf("Выберите индексы этих элементов\n");
    const int k = pozitiv_input();
    check_elements_k(array, k, n);
    
    printf("Так же эта программа выводит индексы тех элементов, которые кратны 3\n");
    index_elements_multiples_three(array, n);

    free(array);
    return 0;
}

int input(void) {
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1) {
        errno = EIO;
        exit(EXIT_FAILURE);
    }
    return value;
}

int pozitiv_input(void) {
    int value = input();
    if (value < 0) {
        errno = EINVAL;
        exit(EXIT_FAILURE);
    }
    return value;
}

void random_filling(size_t *array, const size_t n) {
    for (size_t index = 0; index < n; ++index) {
        array[index] = (rand() % n);
    }
}

void user_input(size_t *array, const size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("Пожалуйста введите числа, исходя из диапазона, который вы сами задали\n");
        array[i] = input();
    }
}

void print_array(const size_t *array, const size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("Ваш массив = %zu\n", array[i]);
    }
}

void check_elements_k(size_t *array, int k, const size_t n) {
    if (k <= 0 || k > n) {
        printf("Неверное значение для k. Должно быть: 0 < k <= размер массива.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = n - k; i < n; ++i) {
        array[i] = -array[i];
    }
    printf("Ваш массив после изменений имеет вид:\n");
    print_array(array, n);
}

void index_elements_multiples_three(const size_t *array, const size_t n) {
    printf("Индексы элементов, кратных 3:\n");
    for (size_t i = 0; i < n; ++i) {
        if (array[i] % 3 == 0) {
            printf("Индекс: %zu\n", i);
        }
    }
}
