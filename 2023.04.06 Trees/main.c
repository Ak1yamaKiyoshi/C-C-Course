#include <stdio.h>
#include <malloc.h>
#include <strings.h>


struct node {
    struct node *left;
    struct node *right;
    int value; 
};

/* 
 * allocate node with given value, left and right pointers will set on NULL
 * @param value int value to create node with 
 * @return node allocated strcut node node with given value  
*/
struct node* allocateNode(int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


/* 
 * calculate node distance to nearest NULL child of this node 
 * @param tree - subtree to begin search in 
 * @param counter distance to nearest node, ! set 0 if starting at root
 * @return left:right distance to nearest NULL child of this node  
*/
int nodeNearestNULLChild(struct node* tree, int counter) {
    if (tree == NULL) return counter;
    int left = nodeNearestNULLChild(tree->left, counter+1);
    int right = nodeNearestNULLChild(tree->right, counter+1);
    return ( left <= right ) ? left : right;
}


/*
 * rightmost insert node into the tree with given value 
 * @param tree struct node* tree to insert value in 
 * @param value value to insert node in tree with
 * @return tree - ! assign return value only if youre creating tree, otherwise it probably be subtree
*/
struct node* insert(struct node* tree, int value) {
    if (tree == NULL) return allocateNode(value);
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
    (nodeNearestNULLChild(tree->left, 0) >= nodeNearestNULLChild(tree->right, 0)) ? 
    insert(tree->left, value) : insert(tree->right, value);
    
    return tree;
}

/* 
 * print binary tree in array look 
 * @param tree tree to print 
*/
void print(struct node* tree) {
    if (tree == NULL) return;
    print(tree->left);
    printf("%d ", tree->value);
    print(tree->right); 
}


/* 
 * print binary tree in tree look 
 * @param tree tree to print 
*/
void fancyPrint(struct node* tree, int space) {
    if (tree == NULL) return;
    space += 5;
    fancyPrint(tree->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) { printf(" "); } printf("[%d]<\n", tree->value);
    fancyPrint(tree->left, space);
}
    

int main() {
    struct node* tree = NULL;
    tree = insert(tree, 1);
    insert(tree, 2);
    insert(tree, 3);
    insert(tree, 5);
    insert(tree, 6);
    insert(tree, 7);
    insert(tree, 8);
    printf("Tree print: ");
    fancyPrint(tree, 1);
    return 0;
}