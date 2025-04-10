//
// Created by glaks on 3/29/2025.
//

#ifndef OBJECT_H
#define OBJECT_H

#include "common.h"
#include "value.h"

#define OBJ_TYPE(value)     (AS_OBJ(value)->type)

#define IS_STRING(value)    isObjType(value, OBJ_STRING)

#define AS_STRING(value)    ((struct ObjString*)AS_OBJ(value))
#define AS_CSTRING(value)   (((struct ObjString*)AS_OBJ(value))->chars)

typedef enum {
    OBJ_STRING,
} ObjType;

struct Obj {
    ObjType type;
    struct Obj* next;
};

struct ObjString {
    struct Obj obj;
    int length;
    char* chars;
    uint32_t hash;
};

struct ObjString* takeString(char* chars, int length);
struct ObjString* copyString(const char* chars, int length);
void printObject(Value value);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

#endif //OBJECT_H
