#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void array_init(array_t *array, GENERIC template)
{
	array->size = 0;
	array->capacity = 4;
	array->template = template;
	array->cargo = malloc(sizeof(template) * array->capacity);
}

void array_append(array_t *array, GENERIC value)
{
    array_update_capacity(array);
    
    if (sizeof(value) == sizeof(array->template)) {
    	array->cargo[array->size++] = value;
    } else {
    	printf("Size Mismatch: Trying to pack var of size %zd into slot of size %zd", sizeof(value), sizeof(array->template));
    }
}

GENERIC array_get(array_t *array, int index)
{
    if (index >= array->size || index < 0) {
        fprintf(stderr, "Index out of Bounds. Size: %d Attempted Index: %d\n", array->size, index);
        return;
    }
    return array->cargo[index];
}

void array_set(array_t *array, int index, GENERIC value)
{
    while (index >= array->size) {
        array_append(array, NULL);
    }
    if (sizeof(value) == sizeof(array->template)) {
    	array->cargo[index] = value;
    } else {
    	fprintf(stderr, "Size Mismatch: Trying to pack var of size %zd into slot of size %zd", sizeof(value), sizeof(array->template));
    }
}

void array_update_capacity(array_t *array)
{
    if (array->size >= array->capacity) {
        array->capacity *= 2;
        array->cargo = realloc(array->cargo, sizeof(array->template) * array->capacity);
        if (array->cargo == NULL) {
        	fprintf(stderr, "Memory Error: Unable to reallocate array")
        }
    }
}

void array_free(array_t *array)
{
    free(array->cargo);
}

int array_length(array_t *array)
{
    return (sizeof(array->cargo) / sizeof(array->template));
}

GENERIC array_type(array_t *array)
{
    return array->template;
}
