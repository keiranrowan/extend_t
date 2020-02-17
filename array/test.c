#include <stdio.h>
#include "array.h"

int main(void) {
    // Create New Array
	array_t array;

	// Initialize with Template Type int
	int template = 0;
	array_init(&array, &template);

	// Set Index 0 to 1
    array_set(&array, 0, 1);
    array_set(&array, 1, 2);
    array_set(&array, 2, 3);

    // Append the Number 7 5 Times
    for (int i = 0 ; i < 5 ; i++) {
        array_append(&array, 7);
    }

    array_insert(&array, 1, 123456);

    array_swap(&array, 0, 1);

    printf(" %d { ", array_length(&array));
    for (int i = 0; i < array_length(&array); i++) {
        //printf("%d\n", array.cargo[i]);
        printf("%d, ", (int)array_get(&array, i));
    }
    printf("}\n");

    printf("\n%d\n", (int)array_pop(&array, 1));

    array_t sub;
    int temp = 0;
    array_init(&sub, &temp);

    array_splice(&array, &sub, 2, 4);

    array_concat(&sub, &array);

    // Print Values
    printf(" %d { ", array_length(&sub));
    for (int i = 0; i < array_length(&sub); i++) {
        //printf("%d\n", array.cargo[i]);
        printf("%d, ", (int)array_get(&sub, i));
    }
    printf("}\n");



    // Free the Array
    array_free(&array);
}
