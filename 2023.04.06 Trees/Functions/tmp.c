
#include <malloc.h>
#include <stdio.h>
#include <strings.h>












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

/*
DFS З корня до нащадків:
      -> Нам потрібно зберігати поточний шлях ( елементи які ми відвідали )
      -> Нам потрібно зберігати значення суми ( після віднімання від неї значення вузла ) 
      -> Якщо ми вже дістались термінального вузла 
            -> Перевірити, чи сума == 0, ( якщо так, то ми знайшли потрібний шлях ) 
      -> Інакше викликати DFS на лівий та правий нащадок
*/
//int *nCalculateTreePath(nnode* tree, int sum) {
//  sum -= tree->value;
//  if (tree->left == NULL && tree->right == NULL && sum == 0) return path;
//  else if (sum != 0) { free(path); return NULL; }
//  else {
//    nCalculateMaxTreePath(tree->right, sum, path, index+1);
//    nCalculateMaxTreePath(tree->left, sum, path, index+1);
//  }
//}




void heightTest() {
  nnode *tree1 = NULL;
  int array[] =  {0,1,2,3,4,5,6,7,8,9,10,11,12,0,1,2,3,4,5,6,7,8,9,10,11,120,1,2,3,4,5,6,7,8,9,10,11,12,0,1,2,3,4,5,6,7,8,9,10,11,12};
  tree1 = nInsertArray(tree1, array, 13*4); 
  nFancyPrint(tree1, 1);
  printf(" Height of tree is %d\n", nHeight(tree1));

}

void testIsTreeIdentical() {
  nnode *tree1 = NULL;
  nnode *tree2 = NULL;
  int array[] =  {0,  1,  100,  3,  4,  5, 70};
  int array1[] = {0,  1,  100,  3,  1,  5, 70};
  tree1 = nInsertArray(tree1, array, 6); 
  tree2 = nInsertArray(tree2, array1, 6); 
  printf(" is trees identical? %s\n", nisTreeIdentical(tree1, tree2) ? "yes" : "no" );
}

void testInsert() {
  nnode *tree = NULL;
  int array[] = {0,  1,  2,  3,  4,  5,   6,     7,    8,   -100,
                 9,  10, 11, 12, 13, -90, 14,    15,   16,  17,
                 18, 19, 20, 21, 22, 23,  -2000, -900, -400};
  tree = nInsertArray(tree, array, 28);

  printf("Tree print: ");
  nFancyPrint(tree, 1);
  printf("\nTree traverses print: ");
  printf("\ntree pre order traversal:  ");
  nPrintPreOrder(tree);
  printf("\ntree in order traversal:   ");
  nPrintInOrder(tree);
  printf("\ntree post order traversal: ");
  nPrintPostOrder(tree);
  printf("\n node with value 3 [post order search]: %d",
  nFindByValue(tree, 3)->value);
  printf("\nminimum of the tree: %d\n", min(tree)->value);
  printf("\n parent of min value: %d",
  nodeParent(tree, min(tree))->value);
}

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

void testMaxPath() {
  nnode *tree = NULL;
  int array[] = {0,  1,  100,  3,  4, 5, 70};
  tree = nInsertArray(tree, array, 7);
  printf("max path: %d \n ", nCalculateMaxTreePath(tree));
  
  printf("Tree print: ");
  nFancyPrint(tree, 1);
}

int main() {
  //testInsert();
  //testRemove();
  //testMaxPath();
  testIsTreeIdentical();
  heightTest();
  return 0;
}