#include "function_for_4.3.h"

int input(void)
{ 
    int value = 0;
    int result = scanf("%d", &value); 
    if (result != 1)
    { 
        perror("Error, you enter impossible value");
        exit(EXIT_FAILURE);
    }

    return value;
}

int pozitiv_input(void)
{ 
    int value = input(); 
    if (value <= 0)
    { 
        perror("Ups, impossible value for size array");
        exit(EXIT_FAILURE);
    }

    return value;
}

int** create_array(const size_t n, const size_t m)
{ 
    int **array = (int**)malloc(n * sizeof(int*));
    check_array(array);
    for(size_t i = 0; i < n; i++)
    { 
        array[i] = (int*)malloc(m * sizeof(int));
        check_array(array[i]);
    }

    return array;
}

void check_array(int **array)
{
    if(!array)
    { 
        perror("Ups, array piteryalsya\n");
        exit(EXIT_FAILURE);
    }
}

void print_array(int **array, const size_t n, const size_t m) {
    check_array(array);
    printf("Your array:\n");
    for (size_t i = 0; i < n; i++) {
        printf("[ ");
        for (size_t j = 0; j < m; j++) {
            printf("%d ", array[i][j]);
        }
        printf("]\n");
    }
}

int **copy_array(int **array, const size_t n, const size_t m)
{ 
    check_array(array);
    int **new_array = create_array(n, m);
    for (size_t i = 0; i < n; i++)
    { 
        for(size_t j = 0; j < m; j++)
        { 
            new_array[i][j] = array[i][j];
        }
    }

    return new_array;
}

void clear_array(int **array, const size_t n, const size_t m)
{ 
    check_array(array);
    for (size_t i = 0; i < n; i++) {
        free(array[i]); 
    }

    free(array);  
}


void random_filling(int **array, const size_t n, const size_t m)
{ 
    check_array(array);
    printf("Your choice random method\n");
    printf("You will need to enter the maximum and minimum range of numbers\n");
    int min = input();
    int max = input();
    if (min >= max)
    { 
        perror("Wow, your have problems with math\n");
        exit(EXIT_FAILURE);
    }

    for(size_t i = 0; i < n; i++)
    { 
        for(size_t j = 0; j < m; j++)
        { 
            array[i][j] = rand() % (max - min + 1) + min;
        }
    }

}

void input_filling(int **array, const size_t n, const size_t m)
{
    check_array(array);
    printf("Please enter elements array:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("String %zu:\n", i + 1);
        for (size_t j = 0; j < m; j++)
        {
            printf("Please enter element [%zu][%zu]: ", i + 1, j + 1);
            array[i][j] = input();
        }
    }
}

int **replace(int **array, const size_t n, const size_t m)
{ 
    check_array(array);
    int **new_array = copy_array(array, n, m);
    for(size_t i = 0; i < n; i++)
    { 
        int max_element = 0;
        for(size_t j = 0; j < m; j++)
        {
            if(new_array[i][max_element] < new_array[i][j])
            {
                max_element = j;
            }
        }
        new_array[i][max_element] = -new_array[i][max_element];
    }

    return new_array;    
}

int max_element_from_array(int **array, const size_t n, const size_t m)
{
    check_array(array);
    int max_element = array[0][0];
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        { 
            if (array[i][j] > max_element)
            {
                max_element = array[i][j];
            }
        }
    }

    return max_element;
}

int counter(int **array, const size_t n, const size_t m)
{
    check_array(array); 
    int max = max_element_from_array(array, n, m); 
    int counter = 0;

    for (size_t j = 0; j < m; j++) 
    {
        for (size_t i = 0; i < n; i++)
        {
            if (array[i][j] == max)
            {
                counter++; 
                break; 
            }
        }
    }

    return counter;
}

int **array_with_column_from_zeros(int **array, const size_t n, const size_t m)
{
    check_array(array);  
    int k = counter(array, n, m); 
    size_t new_m = m + k;
    int **new_array = create_array(n, new_m); 
    size_t current_col = 0;

    
    for (size_t j = 0; j < m; j++) 
    {
        for (size_t i = 0; i < n; i++) 
        {
            new_array[i][current_col] = array[i][j];  
        }
        current_col++;  
        if (array[0][j] == max_element_from_array(array, n, m)) 
        {       
            for (size_t i = 0; i < n; i++) 
            {
                new_array[i][current_col] = 0;  
            }
        current_col++; 
        }
    }

    return new_array;
}