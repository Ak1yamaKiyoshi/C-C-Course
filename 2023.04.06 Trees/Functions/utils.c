#include <stdio.h>
#include "node.c"
#ifndef __utils_c__
#define __utils_c__


/*
 * calculate tree heigth from given pointer
 * @param tree tree to calculate height of
 * @return tree height
*/
int nHeight(nnode *tree) {
  if (tree == NULL) return 0;
  int left = nHeight(tree->left);
  int right = nHeight(tree->right);
  return (left > right) ? left + 1 : right + 1;
}


/*
 * calculate node distance to nearest NULL child of this node
 * @param tree - subtree to begin search in
 * @param counter distance to nearest node, ! set 0 if starting at root
 * @return left:right distance to nearest NULL child of this node
 */
int nearestNULL(nnode *tree, int counter) {
  if (tree == NULL)
    return counter;
  int left = nearestNULL(tree->left, counter + 1);
  int right = nearestNULL(tree->right, counter + 1);
  return (left <= right) ? left : right;
}


/*
 * find parent of given node
 * @param tree search parent of givent nodeToFind in that tree
 * @param nodeToFind parent of that node will be found if exists
 * @return tree parent of nodeToFInd
 */
nnode *nodeParent(nnode *tree, nnode *nodeToFind) {
  if (tree != NULL) {
    if (tree->left == nodeToFind || tree->right == nodeToFind)
      return tree;
    nnode *buffer = nodeParent(tree->left, nodeToFind);
    if (buffer != NULL &&
        (buffer->left == nodeToFind || buffer->right == nodeToFind))
      return buffer;
    buffer = nodeParent(tree->right, nodeToFind);
    if (buffer != NULL &&
        (buffer->left == nodeToFind || buffer->right == nodeToFind))
      return buffer;
    return NULL;
  } else
    return tree;
}


/*
 * * * Algorythm * * * 
  Якщо обидва дерева порожні, то повернути 1
  Інакше - якщо обидва дерева не порожні
    –> Перевірити значення кореня (tree1->data == tree2->data)
    –> Рекурсивно перевірити ліві піддерева
    –> Рекурсивно перевірити праве піддерево
  Якщо вищенаведені три оператори істинні, то повернути 1
  Інакше повернути 0 (одне з них порожнє, а інше ні)
 * * * * * * * * * * * 
 * check if two trees are identical
 * @param tree1 first tree
 * @param tree2 second tree
 * @returns int 1 - identical, 0 - not identical
*/
int nisTreeIdentical(nnode* tree1, nnode* tree2) {
  if (!tree1 && !tree2) return 1;
  if (tree1 && tree2) {
    if (tree1->value == tree2->value
       && nisTreeIdentical(tree1->left, tree2->left)
       && nisTreeIdentical(tree1->right, tree2->right)) 
      return 1;
  }
  return 0;
}


/*
 * calculate max sum of node values path to leaf node in tree 
 * @param tree tree to calculate path in 
 * @return max sum of node values path to leaf node in tree 
*/
int nCalculateMaxTreePath(nnode* tree) {
  if (tree == NULL) return 0;
  int left = nCalculateMaxTreePath(tree->left);
  int right = nCalculateMaxTreePath(tree->right);
  return tree->value + ((left > right) ? left : right);
}


nnode *min(nnode *tree) {
  if (tree != NULL) {

    nnode *minNode = tree;
    nnode *buffer = min(tree->left);
    if (buffer != NULL && minNode->value > buffer->value)
      minNode = buffer;
    buffer = min(tree->right);
    if (buffer != NULL && minNode->value > buffer->value)
      minNode = buffer;
    return minNode;

  } else
    return tree;
}


#endif