# extend_t
extend_t is a set of dynamic types for C

![](https://travis-ci.com/keiranrowan/extend_t.svg?branch=master) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/3740545cf1754cf1b5038eb21028bf24)](https://www.codacy.com/manual/keiranrowan/extend_t?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=keiranrowan/extend_t&amp;utm_campaign=Badge_Grade)![Docker Badge](https://img.shields.io/docker/cloud/build/keiranrowan/extend_t) ![](https://img.shields.io/github/license/keiranrowan/extend_t) ![](https://img.shields.io/github/languages/code-size/keiranrowan/extend_t) ![](https://img.shields.io/github/languages/top/keiranrowan/extend_t)

#### Future Updates
 - Implement C11 _Generic instead of Void Pointers
 - Implement List and Dictionary types

## Array Type

#### Functions
```
[X] _init    -> (array, template)     -> Initializes memory for an Array
[X] _append  -> (array, value)        -> Appends an Item to an Array
[X] _set     -> (array, index, value) -> Sets a value at a specified Index
[X] _get     -> (array, index)        -> Returns the value at a specified Index
[X] _concat  -> (array A, array B)    -> Appends array B to array A
[X] _insert  -> (array, index, value) -> Inserts a value and pushes back array
[X] _delete  -> (array, index)        -> Removes an item and pulls up array
[X] _pop     -> (array, index)        -> Removes an item and returns its value
[X] _swap    -> (array, index, index) -> Swaps two array items
[X] _shuffle -> (array)               -> Randomizes array item indexes
[X] _reverse -> (array)               -> Reverses the array
[X] _splice  -> (array, array B, a, b)-> Sets Array B to Array subsection [a, b] inclusive
[X] _free    -> (array)               -> Cleans up memory allocated by array
[X] _length  -> (array)               -> Returns the length of an array
[X] _type    -> (array)               -> Returns the type of an array

To Be Added After _Generic Implementation: 
[ ] _sort    -> (array)               -> Performs an ascending sort on the array
[ ] _zsort   -> (array)               -> Performs a descending bubble sort on the array
```

#### Example: Init, Append, Set, Get, Insert, Delete, Pop
```C
// Create New Array
array_t array;

// Initialize with Template Type int
int template = 0;
array_init(&array, &template);

// Set First Three Index Values
array_set(&array, 0, 1);
array_set(&array, 1, 2);
array_set(&array, 2, 3);

// Append the Number 7 10 Times
for (int i = 0 ; i < 10 ; i++) {
    array_append(&array, 7);
}

// Insert 123456 at Index 1
array_insert(&array, 1, 123456);

// Delete the First Index
array_delete(&array, 0);

// Print Values
printf(" %d { ", array_length(&array));
for (int i = 0; i < array_length(&array); i++) {
    //printf("%d\n", array.cargo[i]);
    printf("%d, ", (int)array_get(&array, i));
}
printf("}\n");

// Pop and Print Index 2
printf("%d\n", (int)array_pop(&array, 2));

// Free the Array
array_free(&array);
```

#### Example: shuffle, sort, swap, reverse
```C
// Create New Array
array_t array;

// Initialize with Template Type int
int template = 0;
array_init(&array, &template);

// Populate Array
for (int i = 0 ; i < 10 ; i++) {
    array_append(&array, i);
}

// Reverse It
array_reverse(&array);

// Shuffle It
array_shuffle(&array);

// Swap 0 and 6
array_swap(&array, 0, 6);

array_sort(&array);

// Print Values
printf(" %d { ", array_length(&array));
for (int i = 0; i < array_length(&array); i++) {
    //printf("%d\n", array.cargo[i]);
    printf("%d, ", (int)array_get(&array, i));
}
printf("}\n");
```
#### Example: Accessing the Array Directly
```C
// Create New Array
array_t array;

// Initialize with Template Type int
int template = 0;
array_init(&array, &template);

// Populate Array
for (int i = 0 ; i < 10 ; i++) {
    array_append(&array, i);
}

print("%d, %d, %d", array.size, array.capacity, array.cargo[0]);
```

## List

```C
COMING SOON!!!
```

## Dictionary

```C
COMING SOON!!!
```
