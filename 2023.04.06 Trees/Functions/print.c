#include "node.c"
#include <stdio.h>
#ifndef __print_c__
#define __print_c__

/*
 * print binary tree in array look using pre     order traverse
 * @param tree tree to print
 */
void nPrintPreOrder(nnode *tree) {
  if (tree == NULL)
    return;
  nPrintPreOrder(tree->left);
  printf("%d ", tree->value);
  nPrintPreOrder(tree->right);
}

/*
 * print binary tree in array look using in order traverse
 * @param tree tree to print
 */
void nPrintInOrder(nnode *tree) {
  if (tree == NULL)
    return;
  printf("%d ", tree->value);
  nPrintInOrder(tree->left);
  nPrintInOrder(tree->right);
}

/*
 * print binary tree in array look using post order traverse
 * @param tree tree to print
 */
void nPrintPostOrder(nnode *tree) {
  if (tree == NULL)
    return;
  printf("%d ", tree->value);
  nPrintPostOrder(tree->right);
  nPrintPostOrder(tree->left);
}

/*
 * print binary tree in tree look
 * @param tree tree to print
 * @param space spacing between nodes in print (heigher spacing, taller the tree
 * will be)
 */
void nFancyPrint(nnode *tree, int space) {
  if (tree == NULL)
    return;
  space += 5;
  nFancyPrint(tree->right, space);
  printf("\n");
  for (int i = 5; i < space; i++) {
    printf(" ");
  }
  printf("[%d]<\n", tree->value);
  nFancyPrint(tree->left, space);
}


#endif