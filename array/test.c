#include <stdio.h>
#include "array.h"

#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-conversion"

int main(void) {
    // Create New Array
	array_t array;

	// Initialize with Template Type int
	int template = 0;
	array_init(&array, &template);

    // Append the Number 7 5 Times
    for (int i = 0 ; i < 10 ; i++) {
        array_append(&array, i);
    }

    printf(" %d { ", array_length(&array));
    for (int i = 0; i < array_length(&array); i++) {
        //printf("%d\n", array.cargo[i]);
        printf("%d, ", (int)array_get(&array, i));
    }
    printf("}\n");

    array_shuffle(&array);

    printf(" %d { ", array_length(&array));
    for (int i = 0; i < array_length(&array); i++) {
        //printf("%d\n", array.cargo[i]);
        printf("%d, ", (int)array_get(&array, i));
    }
    printf("}\n");


    // Free the Array
    array_free(&array);
}
