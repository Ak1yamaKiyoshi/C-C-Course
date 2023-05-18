#include "./Functions/node.c"
#include "./Functions/remove.c"
#include "./Functions/print.c"
#include <stdio.h>
#ifndef __test_remove_c__
#define __test_remove_c__


void testRemove() {
nnode *tree = NULL;
  int array[] = {1, 2, 3, 4, 5, 6};
  tree = nInsertArray(tree, array, 6); 

  // two child case
nRemoveByValue(tree, 3); 
  // one child case
nRemoveByValue(tree, 4);
  // terminal node case 
nRemoveByValue(tree, 5);
  // root case 
nRemoveByValue(tree, 1);

  printf("Tree print: ");
  nFancyPrint(tree, 1);
}

#endif