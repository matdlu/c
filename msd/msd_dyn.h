#ifndef CHEST_MSD_DYN_H
#include <stdio.h>
#include <stdlib.h>
#include "msd_type.h"
#define CHEST_MSD_DYN_H

typedef struct {
    uintll element_size;
    uintll array_length;
    uintll array_capacity;
    uchar *array;
} MsdDyn;

void msdDynClear(MsdDyn* dyn);
MsdDyn msdDynCreate(uintll element_size, uintll number_of_elements);
int msdDynPush(MsdDyn* dyn, void* element, uintll element_size);
uchar msdDynGet(MsdDyn* dyn, uintll index);

#define MSD_DYN_DEFAULT_CAPACITY 1024
/* uchar */
#define msdDynUcharCreate(number_of_elements) msdDynCreate(sizeof (uchar), number_of_elements)
#define msdDynUcharCreateDefault() msdDynCreate(sizeof (uchar), MSD_DYN_DEFAULT_CAPACITY)
#define msdDynUcharPush(dyn, element) msdDynPush(dyn, element, sizeof (uchar))
#define msdDynUcharGet(dyn, index) (uchar)msdDynGet(dyn, index)
/* char */
#define msdDynCharCreate(number_of_elements) msdDynCreate(sizeof (char), number_of_elements)
#define msdDynCharCreateDefault() msdDynCreate(sizeof (char), MSD_DYN_DEFAULT_CAPACITY)
#define msdDynCharPush(dyn, element) msdDynPush(dyn, element, sizeof (char))
#define msdDynCharGet(dyn, index) (char)msdDynGet(dyn, index)
/* int */
#define msdDynIntCreate(number_of_elements) msdDynCreate(sizeof (int), number_of_elements)
#define msdDynIntCreateDefault() msdDynCreate(sizeof (int), MSD_DYN_DEFAULT_CAPACITY)
#define msdDynIntPush(dyn, element) msdDynPush(dyn, element, sizeof (int))
#define msdDynIntGet(dyn, index) (int)msdDynGet(dyn, index)
/* uint */
#define msdDynUintCreate(number_of_elements) msdDynCreate(sizeof (uint), number_of_elements)
#define msdDynUintCreateDefault() msdDynCreate(sizeof (uint), MSD_DYN_DEFAULT_CAPACITY)
#define msdDynUintPush(dyn, element) msdDynPush(dyn, element, sizeof (uint))
#define msdDynUintGet(dyn, index) (uint)msdDynGet(dyn, index)
#endif //CHEST_MSD_DYN_H

#ifdef MSD_DYN_IMPLEMENTATION
void msdDynClear(MsdDyn* dyn) {
    dyn->element_size = 0;
    dyn->array_length = 0;
    dyn->array_capacity = 0;
    free(dyn->array);
    dyn->array = 0;
}

MsdDyn msdDynCreate(uintll element_size, uintll number_of_elements) {
    MsdDyn dyn;

    if ( number_of_elements > 1 && element_size > 1) {
        dyn.element_size = element_size;
        dyn.array_length = 0;
        dyn.array_capacity = element_size * number_of_elements;
        dyn.array = (uchar*) malloc(dyn.array_capacity);
    } else {
        msdDynClear(&dyn);
    }

    return dyn;
}

/* 0 if failed to allocate memory, -1 if the type is wrong, -2 if dyn array is empty*/
int msdDynPush(MsdDyn* dyn, void* element, uintll element_size) {
    if ( dyn != 0 && dyn->array != 0 ) {
        if (dyn->element_size != element_size) {
            fprintf(stderr, "msdDynPush: WRONG TYPE... SOMEWHERE...\n");
            return -1;
        }

        if ( dyn->element_size * (dyn->array_length + 1) > dyn->array_capacity ) {
            if ( realloc(dyn->array, 2 * dyn->array_capacity) == 0 ) return 0;
            dyn->array_capacity *= 2;
        }

        dyn->array[dyn->element_size * (dyn->array_length + 1) - 1] = *(uchar*)element;

        dyn->array_length++;

        return 1;
    } else {
        return -2;
    }
}

uchar msdDynGet(MsdDyn* dyn, uintll index) {
    return dyn->array[index];
}
#endif // MSD_DYN_IMPLEMENTATION
