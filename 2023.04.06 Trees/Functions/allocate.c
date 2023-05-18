#include "node.c"
#include <malloc.h>
#ifndef __allocate_node_c__
#define __allocate_node_c__

/*
 * allocate node with given value, left and right pointers will set on NULL
 * @param value int value to create node with
 * @return node allocated strcut node node with given value
 */
nnode *allocateNode(int value) {
  nnode *node = (nnode *)malloc(sizeof(nnode));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

#endif