#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

#define N_THREADS 12
typedef union value32 {
    uint32_t u;
    int32_t i;
    float f;
} Value32;

typedef (*cmp_func)(Value32 first, Value32 second);
typedef (*setter_func)(Value32 *dest, void *val);

int write(Value32 *array, uint64_t index, uint64_t max_index, Value32 value);
int read(Value32 *array, uint32_t index, uint64_t max_index,  Value32 *dest);
