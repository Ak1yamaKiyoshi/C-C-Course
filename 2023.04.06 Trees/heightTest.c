#include <stdio.h>
#include "./Functions/utils.c"
#include "./Functions/print.c"

#ifndef __test_heigth_c__
#define __test_heigth_c__

void heightTest() {
  nnode *tree1 = NULL;
  int array[] =  {0,1,2,3,4,5,6,7,8,9,10,11,12,0,1,2,3,4,5,6,7,8,9,10,11,120,1,2,3,4,5,6,7,8,9,10,11,12,0,1,2,3,4,5,6,7,8,9,10,11,12};
  tree1 = nInsertArray(tree1, array, 13*4); 
  nFancyPrint(tree1, 1);
  printf(" Height of tree is %d\n", nHeight(tree1));

}

#endif