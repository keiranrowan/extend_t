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

    // Append the Number 7 10 Times
    for (int i = 0 ; i < 10 ; i++) {
        array_append(&array, 7);
    }

    printf(" %d { ", array_length(&array));
    for (int i = 0; i < array_length(&array); i++) {
        //printf("%d\n", array.cargo[i]);
        printf("%d, ", (int)array_get(&array, i));
    }
    printf("}\n");

    array_insert(&array, 1, 123456);

    // Print Values
    printf(" %d { ", array_length(&array));
    for (int i = 0; i < array_length(&array); i++) {
        //printf("%d\n", array.cargo[i]);
        printf("%d, ", (int)array_get(&array, i));
    }
    printf("}\n");

    // Free the Array
    array_free(&array);
}
