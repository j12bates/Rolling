// ============================= SET TREE =============================

// See more info about this library in the source file `setTree.c'.

#ifndef SETTREE_H
#define SETTREE_H

#include <stdlib.h>
#include <stdbool.h>

// Set Tree Information Structure
typedef struct Base Base;

// Set Print Modes
enum PrintMode {
    PRINT_SETS_UNMARKED,
    PRINT_SETS_MARKED,
    PRINT_SETS_ALL
};

// Construct a Tree
Base *treeConstruct(size_t, unsigned long);

// Destruct a Tree (Deallocate/Free)
void treeDestruct(Base *);

// Mark a Certain Set and Supersets
void treeMark(const Base *, const unsigned long *, size_t);

// Print (Un)Marked Sets
void treePrint(const Base *, enum PrintMode);

#endif
