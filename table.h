//
// Created by glaks on 4/1/2025.
//

#ifndef TABLE_H
#define TABLE_H

#include "common.h"
#include "value.h"
typedef struct {
    struct ObjString* key;
    Value value;
} Entry;
typedef struct {
    int count;
    int capacity;
    Entry* entries;
} Table;

void initTable(Table* table);
void freeTable(Table* table);
bool tableGet(Table* table, struct ObjString* key, Value* value);
bool tableSet(Table* table, struct ObjString* key, Value value);
bool tableDelete(Table* table, struct ObjString* key);
void tableAddAll(Table* from, Table* to);
struct ObjString* tableFindString(Table* table, const char* chars, int length, uint32_t hash);

#endif //TABLE_H
