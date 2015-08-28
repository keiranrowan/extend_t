#include <stdio.h>
#include "array.h"

int main(void) {
	// Array Init, Set, Append, and Free test
    /*
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
    */
    // Array Concatenation Test
    /*
    array_t a;
    int ta;
    array_init(&a, &ta);
    
    array_t b;
    int tb;
    array_init(&b, &tb);
    
    array_append(&a, 1);
    array_append(&a, 1);
    array_append(&a, 1);
    array_append(&a, 1);
    array_append(&a, 1);
    array_append(&a, 1);
    
    array_append(&b, 2);
    array_append(&b, 2);
    array_append(&b, 2);
    array_append(&b, 2);
    array_append(&b, 2);
    array_append(&b, 2);
    
    array_concat(&a, &b);
    
    for (int i = 0 ; i < a.size ; i++) {
        printf("%d", (int)array_get(&a, i));
    }
    
    array_free(&a);
    array_free(&b);
    */
    
    /*
    array_t array;
    int template;
    array_init(&array, &template);
    
    array_append(&array, 1);
    array_append(&array, 1);
    array_append(&array, 1);
    array_append(&array, 1);
    array_append(&array, 1);
    
    array_insert(&array, 1, 1);
    
    */
    
}
