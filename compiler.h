//
// Created by glaks on 2/16/2025.
//

#ifndef COMPILER_H
#define COMPILER_H

#include "vm.h"
#include "object.h"

bool compile(const char* source, Chunk* chunk);

#endif //COMPILER_H
