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
    (nodeNearestNULLChild(tree->left, 0) < nodeNearestNULLChild(tree->right, 0)) ? 
    insert(tree->left, value) : insert(tree->right, value);
    return tree;
}


/*
 * rightmost insert array of values into the tree 
 * @param tree struct node* tree to insert value in 
 * @param array array to insert in tree 
 * @param len lenght of array that will be inserted in tree 
 * @return tree - ! assign return value only if youre creating tree, otherwise it probably be subtree
*/
struct node* insertFromArray(struct node* tree, int *array, int len) {
    for (int i = 0; i < len; i++) 
        if (tree == NULL) tree = insert(tree, array[i]);
        else insert(tree, array[i]);
    return tree;
}


/* 
 * serach node in tree using post order traverse
 * @param tree tree to search value in
 * @param value value to search in list 
 * @return node with given value or NULL 
*/
struct node* searchPostOrder(struct node* tree, int value ) {
    if (tree) {
        struct node* buffer = searchPostOrder(tree->left, value);
        if (buffer) return buffer;
        buffer = searchPostOrder(tree->right, value);
        if (buffer) return buffer;
        if (tree->value == value) return tree;
        else return NULL;
    }
}


/*
* Removes node with exact value
* @param {value} value to search
*/
struct node* remove(struct node* tree, int value) {
    struct node* ptr = searchPostOrder(tree, value);
    if (!ptr) return NULL;
    
    if (ptr->left && ptr->right) {// Both childs
        struct node* pointer = ptr.right; // check right subtree
        while (pointer->left) {
            struct node* prevPointer = pointer;
            pointer = pointer->left; 
        }
        ptr->value = pointer->value; // reassign smallest value to current node
        prevPointer->left = NULL;
        free(pointer);
    }
    else if (ptr->left || ptr->right) { // One child
        //let atr = (ptr.right) ? "right" : "left";
        else {
            ptr.parent[parentCheck(ptr)] = ptr[atr] // parent.ptr = ptr.avaivable node
            ptr[atr].parent = ptr.parent
        }
    }
    else // Leaf Node
        ptr.parent[parentCheck(ptr)] = undefined; // remove link to leaf node 
}


/* 
 * print binary tree in array look using pre order traverse 
 * @param tree tree to print 
*/
void printPreOrder(struct node* tree) {
    if (tree == NULL) return;
    printPreOrder(tree->left);
    printf("%d ", tree->value);
    printPreOrder(tree->right); 
}

/* 
 * print binary tree in array look using in order traverse 
 * @param tree tree to print 
*/
void printInOrder(struct node* tree) {
    if (tree == NULL) return;
    printf("%d ", tree->value);
    printInOrder(tree->left);
    printInOrder(tree->right); 
}

/* 
 * print binary tree in array look using post order traverse 
 * @param tree tree to print 
*/
void printPostOrder(struct node* tree) {
    if (tree == NULL) return;
    printf("%d ", tree->value);
    printPostOrder(tree->right); 
    printPostOrder(tree->left);
}



/* 
 * print binary tree in tree look 
 * @param tree tree to print 
 * @param space spacing between nodes in print (heigher spacing, taller the tree will be)
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
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
    tree = insertFromArray(tree, array, 24);

    if (tree != NULL) {
        printf("Tree print: ");
        fancyPrint(tree, 1);
        printf("\nTree traverses print: ");
        printf("\ntree pre order traversal:  "); printPreOrder(tree);
        printf("\ntree in order traversal:   "); printInOrder(tree);
        printf("\ntree post order traversal: "); printPostOrder(tree);
        printf("\nnode with value 3 [post order search]: %d", searchPostOrder(tree, 3)->value);
    } else printf(" tree is NULL");


    return 0;
}