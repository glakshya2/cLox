//
// Created by glaks on 3/29/2025.
//


#include "object.h"

#include <stdio.h>
#include <string.h>

#include "memory.h"
#include "value.h"
#include "vm.h"

#define ALLOCATE_OBJ(type, objectType)  \
    (type*)allocateObject(sizeof(type), objectType)

static struct Obj* allocateObject(size_t size, ObjType type) {
    struct Obj* object = (struct Obj*) reallocate(NULL, 0, size);
    object->type = type;
    object->next = vm.objects;
    vm.objects = object;
    return object;
}

static ObjStirng* allocateString(char* chars, int length) {
    struct ObjString* string = ALLOCATE_OBJ(struct ObjString, OBJ_STRING);
    string->length = length;
    string->chars = chars;
    return string;
}

struct ObjString* takeString(char* chars, int length) {
    return allocateString(chars, length);
}

ObjStirng* copyString(const char* chars, int length) {
    char* heapChars = ALLOCATE(char, length + 1);
    memcpy(heapChars, chars, length);
    heapChars[length] = '\0';
    return allocateString(heapChars, length);
}

void printObject(Value value) {
    switch (OBJ_TYPE(value)) {
        case OBJ_STRING:
            printf("%s", AS_CSTRING(value));
            break;
    }
}