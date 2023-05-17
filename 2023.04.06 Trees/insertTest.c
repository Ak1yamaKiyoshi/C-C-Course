#include <malloc.h>
#include <stdio.h>
#include <strings.h>
#include "node.c" // Node structure 
#include "tree.c" // Tree functions 


void testInsert() {
nnode *tree = NULL;
  int array[] = {0,  1,  2,  3,  4,  5,   6,     7,    8,   -100,
                 9,  10, 11, 12, 13, -90, 14,    15,   16,  17,
                 18, 19, 20, 21, 22, 23,  -2000, -900, -400};
  tree = nInsertArray(tree, array, 28);

  printf("Tree print: ");
  nFancyPrint(tree, 1);
  printf("\nTree traverses print: ");
  printf("\ntree pre order traversal:  ");
  nPrintPreOrder(tree);
  printf("\ntree in order traversal:   ");
  nPrintInOrder(tree);
  printf("\ntree post order traversal: ");
  nPrintPostOrder(tree);
  printf("\n node with value 3 [post order search]: %d",
  nFindByValue(tree, 3)->value);
  printf("\nminimum of the tree: %d\n", min(tree)->value);
  printf("\n parent of min value: %d",
  nodeParent(tree, min(tree))->value);
}
