#include "function_for_4.3.h"

int main(void)
{ 
    printf("please enter the number of lines in your array\n");
    const size_t n = (size_t)pozitiv_input();
    printf("Please, enter the number of column in your array\n");
    const size_t m = (size_t)pozitiv_input();
    int **array = create_array(n, m);

    printf("Please, choice method for filling array\n");
    printf("%d - input filling, %d - random fiiling\n", INPUT, RANDOM);
    int choice = input(); 
    switch(choice)
    { 
        case INPUT:
            input_filling(array, n, m);
            break;
        case RANDOM:
            random_filling(array, n, m);
            break;
        default:
            perror("Error, your choice impossible method\n");
            exit(EXIT_FAILURE);
    }
    print_array(array, n, m);
    

    printf("This programm replace max element in lines to the opposite\n");
    int **new_array = replace(array, n, m);
    print_array(new_array, n, m);
    clear_array(new_array, n, m);

    printf("Also this programm inserts a column of zeros");
    printf("after each column containing the maximum element of the array\n\n");
    printf("Let me remind you\n");
    print_array(array, n, m);
    int **new_array_2 = array_with_column_from_zeros(array, n, m);
    print_array(new_array_2, n, m + counter(array, n, m));
    
    clear_array(new_array_2, n, m); 
    clear_array(array, n, m);

    return 0;
}