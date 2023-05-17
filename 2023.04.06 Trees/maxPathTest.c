#include <malloc.h>
#include <stdio.h>
#include <strings.h>
#include "node.c" // Node structure 
#include "tree.c" // Tree functions 


void testMaxPath() {
  nnode *tree = NULL;
  int array[] = {0,  1,  100,  3,  4, 5, 70};
  tree = nInsertArray(tree, array, 7);
  printf("max path: %d \n ", nCalculateMaxTreePath(tree));
  
  printf("Tree print: ");
  nFancyPrint(tree, 1);
}