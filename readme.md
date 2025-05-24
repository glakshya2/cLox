# CLOX implementation from the book crafting interpreters

## TODO
1. Devise an encoding that compresses the line information for a series of instructions on the same line. Change writeChunk() to write this compressed form, and implement a getLine() function that, given the index of an instruction, determines the line where the instruction occurs.
2. Implement OP_CONSTANT_LONG for 24-bit numbers
3. 