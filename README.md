# extend_t
extend_t is a set of dynamic types for C

![](https://travis-ci.com/keiranrowan/extend_t.svg?branch=master) ![](https://img.shields.io/codacy/grade/24147cd349c8416497d29a92cd65975b) ![](https://img.shields.io/github/license/keiranrowan/extend_t) ![](https://img.shields.io/github/languages/code-size/keiranrowan/extend_t) ![](https://img.shields.io/github/languages/top/keiranrowan/extend_t)

#### Future Updates
 - Implement C11 _Generic instead of Void Pointers
 - Implement List and Dictionary types

## Array Type

#### Functions
```
 _init    -> (array, template)     -> Initializes memory for an Array
 _append  -> (array, value)        -> Appends an Item to an Array
 _set     -> (array, index, value) -> Sets a value at a specified Index
 _get     -> (array, index)        -> Returns the value at a specified Index
 _concat  -> (array A, array B)    -> Appends array B to array A
 _insert  -> (array, index, value) -> Inserts a value and pushes back array
 _delete  -> (array, index)        -> Removes an item and pulls up array
 _pop     -> (array, index)        -> Removes an item and returns its value
 _promote -> (C array, array)      -> Converts a C Array to an array_t
 _demote  -> (array, C array)      -> Converts an array_t to a C Array
 _shift   -> (array, +/-offset)    -> Shifts the array left or right
 _sort    -> (array)               -> Performs an ascending sort on the array
 _zsort   -> (array)               -> Performs a descending bubble sort on the array
 _swap    -> (array, index, index) -> Swaps two array items
 _shuffle -> (array)               -> Randomizes array item indexes
 _reverse -> (array)               -> Reverses the array
 _shift   -> (array, +/-offset)    -> Shifts the array left or right
 _rsort   -> (array)               -> RETURNS an ascending sorted array
 _rzsort  -> (array)               -> Returns a descending sorted array
 _rswap   -> (array, index, index) -> Returns an array with two swapped array items
 _rshuffle-> (array)               -> Returns an array with randomized items
 _rreverse-> (array)               -> Returns a reversed array
 _rshift  -> (array, +/-offset)    -> Returns a shifted array
 _splice  -> (array)               -> Returns a section of the array
 _free    -> (array)               -> Cleans up memory allocated by array
 _length  -> (array)               -> Returns the length of an array
 _type    -> (array)               -> Returns the type of an array
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

#### Example: shuffle, sort, swap, shift, reverse
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

// Shift Array 2 Indices Right 
array_shift(&array, 2);

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