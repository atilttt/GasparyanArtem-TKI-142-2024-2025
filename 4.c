#include "4.h"

int main(void)
{ 
    printf("Введите размер массива\n");
    const size_t n = pozitiv_input();
    int* array = (int*)malloc(n * sizeof(int));
    check_array(array);
    printf("Пожалуйста, выберите каким методом вы хотите воспользоваться.\n");
    printf("Метод заполнения с помощью ввода - 0, метод рандомного заполнения - 1\n");
    int dependet = pozitiv_input();
    switch(dependet)
    { 
        case INPUT:
            user_input(array, n);
            break;
        case RANDOM:
            printf("Введите минимальное и максимальное значение\n");
            const int min = input(); 
            const int max = input();
            random_filling(array, n, min, max);
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

    printf("Введите произвольное число K\n");
    const int nember = input();
    sum_paired_elements(array, n, k);

    free(array);
    return 0;
}

int input(void) {
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1) {
        errno = EIO;
        perror("Ошибка ввода\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

int pozitiv_input(void) {
    int value = input();
    if (value < 0) {
        errno = EINVAL;
        perror("Ошибка ввода\n");
        exit(EXIT_FAILURE);
    }
    return (size_t)value;
}

void random_filling(int *array, const size_t n, const int min, const int max) {
    check_array(array);
    if (min > max)
    { 
        printf("Неправильно введенные значениея\n");
        exit(1); 
    }

    for (size_t index = 0; index < n; ++index) {
        array[index] = (rand() % (max - min + 1) + min);
    }
}

void user_input(int *array, const size_t n) {
    check_array(array);
    for (size_t i = 0; i < n; ++i) {
        printf("Введите %zu-ый элемент\n");
        array[i] = input();
    }
}

void print_array(const int *array, const size_t n) {
    check_array(array);
    printf("Ваш массив:\n");
    for (size_t i = 0; i < n; ++i) {
        printf("{ %d }", array[i]);
    }
}

void check_array(int *array)
{ 
    if (array == NULL)
    { 
        printf("Произошла ошибка\n");
        exit(1);
    }
}

int* copy_array(const int* array, const size_t n)
{ 
    int *new_array = (int*)malloc(n * sizeof(int));
    check_array(new_array);
    for (size_t i = 0; i < n; ++i)
    { 
        new_array[i] = array[i];
    }

    return new_array;
}

void check_elements_k(int *array, int k, const size_t n) {
    check_array(array);
    if (k <= 0 || k > n) {
        printf("Неверное значение для k. Должно быть: 0 < k <= размер массива.\n");
        exit(1);
    }

    int* array_2 = copy_array(array, n);
    check_array(array_2);
    for (size_t i = n - k - 1; i < n; ++i)
    { 
        array_2[i] = array_2[-i];
    }

}

void index_elements_multiples_three(const int *array, const size_t n) {
    check_array(array);
    printf("Индексы элементов, кратных 3:\n");
    for (size_t i = 0; i < n; ++i) {
        if (array[i] % 3 == 0) {
            printf("Индекс: %zu\n", i);
        }
    }
}

void sum_paired_elements(int *array, const size_t n, const int number)
{ 
    check_array(array);
    size_t count = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if ((array[i] + array[i++]) == number)
        {
            count++;
        }
    }
    printf("В вашем массиве %d пар, сумма которых = %d\n", count, number);

}
