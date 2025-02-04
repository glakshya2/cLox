//
// Created by glaks on 2/4/2025.
//

#ifndef DEBUG_H
#define DEBUG_H
#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);
#endif //DEBUG_H
