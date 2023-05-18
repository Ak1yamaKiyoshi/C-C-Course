#include "node.c"
#include "allocate.c"
#include "utils.c"
#ifndef __insert_node_c__
#define __insert_node_c__


/*
 * rightmost insert node into the tree with given value
 * @param tree nnode* tree to insert value in
 * @param value value to insert node in tree with
 * @return tree - ! assign return value only if youre creating tree, otherwise
 * it probably be subtree
 */
nnode *insert(nnode *tree, int value) {
  if (tree == NULL)
    return allocateNode(value);
  /* check if left tree is not null, if so, insert node at left */
  else if (tree->left == NULL) {
    tree->left = allocateNode(value);
    return tree;
  }
  /* check if right tree is not null, if so, insert node at right */
  else if (tree->right == NULL) {
    tree->right = allocateNode(value);
    return tree;
  }
  (nearestNULL(tree->left, 0) < nearestNULL(tree->right, 0))
      ? insert(tree->left, value)
      : insert(tree->right, value);
  return tree;
}


/*
 * rightmost insert array of values into the tree
 * @param tree nnode* tree to insert value in
 * @param array array to insert in tree
 * @param len lenght of array that will be inserted in tree
 * @return tree - ! assign return value only if youre creating tree, otherwise
 * it probably be subtree
 */
nnode *nInsertArray(nnode *tree, int *array, int len) {
  for (int i = 0; i < len; i++)
    if (tree == NULL)
      tree = insert(tree, array[i]);
    else
      insert(tree, array[i]);
  return tree;
}

#endif