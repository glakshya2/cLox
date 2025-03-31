//
// Created by glaks on 2/4/2025.
//

#include <stdlib.h>

#include "memory.h"
#include "vm.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, newSize);
    if (result == NULL) exit(1);
    return result;
}

static void freeObject(struct Obj* object) {
    switch (object->type) {
        case OBJ_STRING: {
            struct ObjString* string = (struct ObjString*) object;
            FREE_ARRAY(char, string->chars, string->length + 1);
            FREE(struct ObjString, object);
            break;
        }
    }
}

void freeObjects() {
    struct Obj* object = vm.objects;
    while (object != NULL) {
        struct Obj* next = object->next;
        freeObject(object);
        object = next;
    }
}