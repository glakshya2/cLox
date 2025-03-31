WIP

# TODO
1. Use RLE to encode line information for a series of instructions on the same line.
2. Implement OP_CONSTANT_LONG with 24 bit number.
3. Dynamically resize stack.
4. Use flexible array members to store the ObjString and it's character array in a single contiguous allocation.
5. Keep track of which ObjStrings own their character array and which are "constant strings" that just point back to the original source string or some non-freeable location.
6. 