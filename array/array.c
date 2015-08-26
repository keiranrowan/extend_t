#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void array_init(array_t *array, GENERIC template)
{
	array->size = 0;
    if (MODE == PERFORMANCE) {
        array->capacity = PERFORMANCE_INITIAL_CAPACITY;
    } else if (MODE == SIZE) {
        array->capacity = SIZE_INITIAL_CAPACITY;
    } else if (MODE == BIGDATA) {
        array->capacity = BIGDATA_INITIAL_CAPACITY;
    }
    array->template = template;
	array->cargo = malloc(sizeof(template) * array->capacity);
    
    if (array->cargo == NULL) {
        fprintf(stderr, ERROR_MEMORY "\n")
    }
}

void array_append(array_t *array, GENERIC value)
{
    array_update_capacity(array);
    
    if (sizeof(value) == sizeof(array->template)) {
    	array->cargo[array->size++] = value;
    } else {
    	fprintf(stderr, ERROR_TYPE "\n", sizeof(value), sizeof(array->template));
    }
}

GENERIC array_get(array_t *array, int index)
{
    if (index >= array->size || index < 0) {
        fprintf(stderr, ERROR_INDEX "\n", array->size, index);
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
    	fprintf(stderr, ERROR_TYPE "\n", sizeof(value), sizeof(array->template));
    }
}

void array_update_capacity(array_t *array)
{
    if (MODE == PERFORMANCE) {
        if (array->size >= array->capacity) {
            array->capacity *= 2;
            array->cargo = realloc(array->cargo, sizeof(array->template) * array->capacity);
            if (array->cargo == NULL) {
                fprintf(stderr, ERROR_MEMORY "\n")
            }
        }
    } else if (MODE == SIZE) {
        if (array->size >= array->capacity) {
            array->capacity += 1;
            array->cargo = realloc(array->cargo, sizeof(array->template) * array->capacity);
            if (array->cargo == NULL) {
                fprintf(stderr, ERROR_MEMORY "\n")
            }
        }
    } else if (MODE == BIGDATA) {
        // TODO: Implement
    } else {
        fprintf(stderr, ERROR_OPTIMIZATION "\n")
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
