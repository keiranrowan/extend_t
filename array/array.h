#ifndef __array_h__
#define __array_h__

#define GENERIC void*

typedef struct {
	int capacity;
	int size;
    GENERIC template;
	GENERIC *cargo;
} array_t;

// -- Manipulative Operations --

void array_init(array_t *array, GENERIC template);

void array_append(array_t *array, GENERIC  value);

void array_set(array_t *array, int index, GENERIC value);

GENERIC array_get(array_t *array, int index);

void array_free(array_t *array);

// -- Informational Operations --

int array_length(array_t *array);

GENERIC array_type(array_t *array);

// -- Behind the Scenes --

void array_update_capacity(array_t *array);

#endif
