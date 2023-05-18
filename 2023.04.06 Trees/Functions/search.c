#include "utils.c"
#include "node.c"
#include <stdio.h>
#ifndef __search_c__
#define __search_c__

const char NOTHING_TO_SEARCH = 0x0; /* 0b00000000 */
const char USE_VALUE = 0x1;         /* 0b00000001 (1 - use, 0 - do not use) */
const char DEPPEST = 0x2;           /* 0b00000010 (1 - lowerest/deepest, 0 - highest */
const char USE_DEPTH = 0x4;         /* 0b00000100 (1 - use, 0 - do not use) */
const char LEFT_RIGHT = 0x8;        /* 0b00001000 (1 - right child, 0 - left child */
const char USE_CHILD_NODE = 0x10;   /* 0b00010000 (1 - use node pointer as child, 0 - do not use */
const char USE_PARENT = 0x20;       /* 0b00100000 (1 - use node pointer as parent, 0 - do not use) */
const char WITHOUT_CHILD = 0x40;    /* 0b01000000 (1- search for node without child, 0 - do not use) */
const char WITH_CHILD = 0x80;       /* 0b10000000 (1 - search for node with child, 0 - do not use) */



/*
 * search node in tree BY VALUE using post order traverse
 * @param tree tree to search value in
 * @param value value to search in list
 * @return node with given value or NULL
 */
nnode *nFindByValue(nnode *tree, int value) {
  if (tree != NULL) {
    /* seach node in left subtree */
    nnode *buffer = nFindByValue(tree->left, value);

    /* if node found in previous call, return it */
    if (buffer != NULL && buffer->value == value)
      return buffer;

    /* seach node in right subtree */
    buffer = nFindByValue(tree->right, value);

    /* if node found in previous call, return it */
    if (buffer != NULL && buffer->value == value)
      return buffer;

    /* found node with right value */ 
    if (tree->value == value) return tree;
  
    /* node not found */
    else return NULL;
  }
  return NULL;
}


// nnode * find(nnode *root, int *value, nnode ptrnode, char bitset)
// { 
//   
//   
//   if (bitset & DEPPEST) ;
//   if (bitset & LEFT_RIGHT) ;
//   if (bitset & USE_CHILD_NODE) ;
//   if (bitset & WITHOUT_CHILD) ;
//   if (bitset & WITH_CHILD) ;
//   
//   if (!root) return root;
//   if (!(bitset | NOTHING_TO_SEARCH)) return NULL;
// 
//   
//   if ( bitset & USE_VALUE && root->value == value) return root;
//   nnode *result = find(root->left, value, ptrnode, bitset);
//   
//   //if ((bitset & USE_DEPTH)) return result; 
//   if (!result) result = find(root->right, value, ptrnode, bitset);
//   //if (!(bitset & USE_DEPTH)) return result;
// 
// }

/*
 * find node with minimal value in tree
 * @param tree to search in
 * @return minNode node with min value
 */
#endif