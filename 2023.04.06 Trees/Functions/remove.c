#include "node.c"
#include "utils.c"
#include <stdio.h>
#ifndef __remove_c__
#define __remove_c__


/*
 * remove lass node by given value from tree
 * @param tree tree to remove node from
 * @param value value of node to remove
 * @return tree - pointer to tree  
*/
nnode *nRemoveByValue(nnode *tree, int value) {
  // 1. find node with given value 
  nnode *nodePtr = nFindByValue(tree, value);

  // 2. find minimum value of it's subtrees 
  nnode *minNode = min(nodePtr->left);
  nnode *bufferNode = min(nodePtr->right);

  // 3. assign minimum value to minNode 
  if ( minNode != NULL && bufferNode != NULL) 
    minNode = (minNode->value < bufferNode->value) ? minNode : bufferNode;
  else if (minNode == NULL && bufferNode != NULL)
    minNode = bufferNode;
  else if ( minNode == NULL && bufferNode == NULL)
    minNode = nodePtr; 
  
  // 4.find parent of minNode
  if (minNode != NULL)
    bufferNode = nodeParent(tree, minNode);

  // 5. assign value of minimum node to current node 
  if ( nodePtr != minNode )
    nodePtr->value = minNode->value;

  // 6. free and delete pointer to buffer node ( can be current node or can be minimum node in subtrees of current node )
  if (bufferNode != NULL && bufferNode->left == minNode) {
    free(bufferNode->left);
    bufferNode->left = NULL;
  } 
  else if (bufferNode != NULL) {
    free(bufferNode->right);
    bufferNode->right = NULL;
  } 

  return tree;
}

#endif