#include <stdio.h>
#include "array.h"
#include "asistant.h"

void task1(Array *arr)
{
    if (!arr) return;

    size_t arr_size = array_size(arr);

    Array *array_of_even_numbers = NULL;
    size_t new_array_size = 0;
    for (size_t i = 0; i < arr_size; i++) {
        if (array_get(arr, i) % 2 == 0) {
            new_array_size++;
        }
    /* Читаем второй массив */
    }

    array_of_even_numbers = array_create(new_array_size);
    size_t index = 0;

    for (size_t i = 0; i < arr_size; i++) {
        if (array_get(arr, i) % 2 == 0) {
            array_set(array_of_even_numbers, index++, Data(i));
        }
    }

    for (size_t i = 0; i < new_array_size; i++) {
        if (i) printf(" ");
        printf("%d", array_get(array_of_even_numbers, i));
    }
    printf("\n");

    array_delete(array_of_even_numbers);
}


int main(int argc, char **argv)
{
    if (argc < 2) return 1;

    FILE *input = fopen(argv[1], "r");
    if (!input) return 1;

    Array *arr = array_create_and_read(input);
    if (!arr) { fclose(input); return 1; }

    task1(arr);
    array_delete(arr);

    fclose(input);
    return 0;
}