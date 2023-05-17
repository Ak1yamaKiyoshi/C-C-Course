#include <malloc.h>
#include <stdio.h>
#include <strings.h>
#include "node.c" // Node structure 
#include "tree.c" // Tree functions 


void testRemove() {
nnode *tree = NULL;
  int array[] = {1, 2, 3, 4, 5, 6};
  tree = nInsertArray(tree, array, 6); 

  // two child case
nRemoveByValueremoveLast(tree, 3); 
  // one child case
nRemoveByValueremoveLast(tree, 4);
  // terminal node case 
nRemoveByValueremoveLast(tree, 5);
  // root case 
nRemoveByValueremoveLast(tree, 1);

  printf("Tree print: ");
  nFancyPrint(tree, 1);
}