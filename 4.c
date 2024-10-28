#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

/**
* @brief Получает целое число от пользователя.
* @return Введенное целое число; завершает выполнение, если ввод некорректен.
*/
int getInt(void);

/**
 * @brief Проверяет, что введенное значение положительно.
 * @return Положительное число; завершает выполнение, если число некорректно.
 */
int getPosInt(void);

/**
 * @brief Показывает меню для выбора способа заполнения массива.
 */
void showMenu(void);

/**
* @brief Проверяет, что k меньше или равно размеру массива.
* @param k Количество последних элементов для инвертирования.
* @param n Размер массива.
 */
void checkK(int k, int n);

/**
* @brief Заполняет массив случайными числами в диапазоне [-100, 100].
* @param arr Указатель на массив.
* @param n Размер массива.
 */
void fillRand(int* arr, int n);

/**
* @brief Заполняет массив значениями, введенными пользователем.
* @param arr Указатель на массив.
* @param n Размер массива.
 */
void fillUser(int* arr, int n);

/**
* @brief Инвертирует знак последних k элементов массива.
* @param arr Указатель на массив.
* @param n Размер массива.
* @param k Количество последних элементов для инвертирования знака.
 */
void invertLastK(int* arr, int n, int k);

/**
* @brief Выводит индексы элементов массива, кратных 3.
* @param arr Указатель на массив.
* @param n Размер массива.
 */
void printMult3Idx(int* arr, int n);

/**
* @brief Проверяет наличие пары соседних элементов с заданной суммой.
* @param arr Указатель на массив.
* @param n Размер массива.
* @param sum Искомая сумма.
* @return Возвращает 1, если пара найдена; 0 — если нет.
 */
int findAdjSum(int* arr, int n, int sum);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
 */
int main(void) {
    printf("Введите размер массива: ");
    int n = getPosInt();
    int* arr = (int*)malloc(n * sizeof(int));

    showMenu();
    int choice = getInt();
    
    switch (choice) {
        case 1:
            srand(time(0));
            fillRand(arr, n);
            printf("Массив случайных чисел: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2:
            fillUser(arr, n);
            break;
        default:
            errno = ERANGE;
            perror("Ошибка: Неверный выбор\n");
            exit(EXIT_FAILURE);
    }

    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Введите количество последних элементов для инвертирования: ");
    int k = getPosInt();
    checkK(k, n);
    invertLastK(arr, n, k);

    printf("Массив после инвертирования последних %d элементов: ", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printMult3Idx(arr, n);

    printf("Введите искомую сумму: ");
    int targetSum = getInt();
    findAdjSum(arr, n, targetSum);

    free(arr);
    return 0;
}

int getInt(void) {
    int val = 0;
    int res = scanf("%d", &val);
    if (res != 1) {
        errno = EIO;
        perror("Ошибка ввода!");
        exit(EXIT_FAILURE);
    }
    return val;
}

int getPosInt(void) { 
    int val = getInt();
    if (val <= 0) { 
        errno = EINVAL;
        perror("Число должно быть положительным\n");
        exit(EXIT_FAILURE);
    }
    return val;
}

void showMenu(void) {
    printf("Выберите способ заполнения массива:\n");
    printf("1 - Случайные числа\n");
    printf("2 - Ввод с клавиатуры\n");
}

void fillRand(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 201) - 100;
    }
}

void checkK(int k, int n) {
    if (k > n || k < 0) {
        errno = ERANGE;
        perror("Ошибка: Некорректное значение\n");
        exit(EXIT_FAILURE);
    }
}

void fillUser(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Введите элемент %d: ", i);
        arr[i] = getInt();
    }
}

void invertLastK(int* arr, int n, int k) {
    for (int i = n - k; i < n; i++) {
        arr[i] = -arr[i];
    }
}

void printMult3Idx(int* arr, int n) {
    printf("Индексы элементов, кратных 3: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 3 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int findAdjSum(int* arr, int n, int sum) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] + arr[i + 1] == sum) {
            printf("Пара с суммой %d найдена: элементы %d и %d (индексы %d и %d)\n", sum, arr[i], arr[i + 1], i, i + 1);
            return 1;
        }
    }
    printf("Пара с суммой %d не найдена.\n", sum);
    return 0;
}
