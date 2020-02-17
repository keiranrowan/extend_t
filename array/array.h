#ifndef __array_h__
#define __array_h__

#define GENERIC void*

/* == OPTIMIZATION Definition ==
 * There are three optimization methods used when dealing with an
 * array_t. The first is PERFORMANCE, which doubles the array size
 * when the capacity is reached in turn reducing the number of 
 * (expensive) calls to realloc(). The second is SIZE, which keeps
 * the capacity equal to the size. This reduces the size of the array
 * and only allocates that which it needs. The third option for
 * optimization is BIGDATA, which is a combination between PERFORMANCE
 * and SIZE. When using PERFOMANCE the arrays growth is exponential to
 * the number of items in which it has. This becomes a problem when
 * dealing with large arrays because in these circumstances performance
 * is important; however, this method is a modified version of PERFORMANCE
 * that makes it not eat all of your memory.
 */

typedef enum {
    PERFORMANCE,
    SIZE,
    BIGDATA
} OPTIMIZATION;

/* == Settings == */

#define MODE PERFORMANCE

#define PERFORMANCE_INITIAL_CAPACITY    4
#define PERFORMANCE_EXPANSE_FACTOR      2

#define SIZE_INITIAL_CAPACITY           0

#define BIGDATA_INITIAL_CAPACITY        4
#define BIGDATA_EXPANSE_FACTOR          2
#define BIGDATA_THRESHOLD               30000
#define BIGDATA_INCREMENT               200

#define ERROR_MEMORY                    "Memory Error: Unable to Obtain Memory for Allocation"
#define ERROR_TYPE                      "Type Error: Attempting to fit type of size %zd into slot of size %lu"
#define ERROR_OPTIMIZATION              "Optimization Error: Mode not defined"
#define ERROR_INDEX                     "Index Error: Index out of bounds. Size: %u Attempted Index: %d"
#define ERROR_CONCAT                    "Concat Error: Incompatible Types"
#define ERROR_OOB                        "Out of Bounds Error: Invalid argument"

/* == array_t Definition ==
 * capacity -> Used for memory allocation to prevent frequent realloc
 * size     -> The size of the array being used
 * template -> Variable used to determine slot size
 * cargo    -> The array data
 */

typedef struct {
	unsigned int capacity;
	unsigned int size;
	GENERIC template;
	GENERIC *cargo;
} array_t;

void array_init(array_t *array, GENERIC template);
void array_append(array_t *array, GENERIC value);
void array_set(array_t *array, int index, GENERIC value);
GENERIC array_get(array_t *array, int index);
void array_concat(array_t *a, array_t *b);
void array_insert(array_t *array, int index, GENERIC value);
void array_delete(array_t *array, int index);
GENERIC array_pop(array_t *array, int index);
// void array_shift(array_t *array, int offset);
void array_swap(array_t *array, int a, int b);
void array_shuffle(array_t* array);
void array_reverse(array_t *array);
void array_splice(array_t *in, array_t *out, int a, int b);
void array_free(array_t *array);
int array_length(array_t *array);
GENERIC array_type(array_t *array);
void array_update_capacity(array_t *array);

#endif
