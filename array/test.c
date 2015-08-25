#include <stdio.h>
#include "array.h"

int main(void) {
	array_t array;
	int template = 0;
	array_init(&array, &template);

    array_set(&array, 0, 1);
    
    for (int i = 0 ; i < 200 ; i++) {
        array_append(&array, 69);
    }
    
    
    
    printf("%d\n", (int)array_get(&array, 0));
    printf("%d\n", (int)array_get(&array, 200));
    printf("%d\n", (int)array_get(&array, 201));
    
    array_free(&array);
}
