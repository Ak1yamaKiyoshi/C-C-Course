#include <stdio.h>
#include <malloc.h>

struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
};


typedef struct Node nNode; 


nNode* allocateNode(int value, nNode *prev, nNode *next) {
    nNode *node = (nNode*)malloc(sizeof(nNode));
    node->value = value;
    node->next = next;
    node->prev = prev;
    return node;
}



/* a <-> b <-> c
        to 
      a <-> c    */
void unlinkMiddleNode(nNode *a, nNode *b, nNode *c) {
    a->next = c;
    c->prev = a;
    b->next = NULL;
    b->prev = NULL;
}


// a <-> b <-> c
void link(nNode *a, nNode *b, nNode *c) {
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
}


nNode* moveLast(nNode *list) {
    while (list && list->next) list = list->next;
    return list;
}


nNode* moveFirst(nNode *list) {
    while (list && list->prev) list = list->prev;
    return list;
}


nNode* findByValue(nNode *list, int value) {
    list = moveFirst(list);
    while (list->next && list->value != value) 
        list = list->next;
    
    if (list->value == value)
        return list;

    else return NULL;
}


nNode* moveToIndex(nNode *list, int index) {
    list = moveFirst(list);
    int k = 0;
    while (list->next && k < index) {
        list = list->next;
        k++;
    }
    if (k == index)
        return list;
    else return NULL;
}


void insert(nNode *list, int value, int index) {
    list = moveToIndex(list, index);
    nNode *newNode = allocateNode(value, NULL, NULL);
    link(list->prev, newNode, list);
}


void insertFirst(nNode *list, int value) {
    list = moveFirst(list);
    link(allocateNode(value, NULL, NULL), list, list->next); 
}


void insertLast(nNode *list, int value) {
    list = moveLast(list);
    link(list->prev, list, allocateNode(value, NULL, NULL)); 
}


void print(nNode *list) {
    list = moveFirst(list);
    while (list) { // while list is not NULL
        printf("%d ", list->value); // print current node value 
        list = list->next; // move list pointer to prev node 

    }
}


void printBackwards(nNode *list) {
    list = moveLast(list);
    while (list) { // while list is not NULL
        printf("%d ", list->value); // print current node value 
        list = list->prev; // move list pointer to prev node 

    }
}

void insertLastFromArray(nNode *list, int *array, int len) {
    for (int i = 0; i < len; i++) 
        insertLast(list, array[i]);
}

void insertFirstFromArray(nNode *list, int *array, int len) {
    for (int i = 0; i < len; i++) 
        insertFirst(list, array[i]);
}


int length(nNode *list) {
    int lenght = 0;
    for (;list; list=list->next, lenght++);
    return lenght;
}


int indexOf(nNode *list, int value) {
    int i = 0;
    while (list && list->value != value) {
        list = list->next;
        i++;
    } 
    
    if (list->value == value)
        return i;
    else return -1;
}


nNode* delete(nNode* list, int index) {
    list = moveToIndex(list, index);
    nNode* tmp1 = list->prev;
    nNode* tmp2 = list->next;
    unlinkMiddleNode(tmp1, list, tmp2);
    free(list);
    
    list = (tmp1) ? tmp1 : tmp2;
}


nNode *removeFirst(nNode *list, int value) {    
    list = moveFirst(list);
    if (list) {
        nNode *tmp = list;
        nNode *tmp2;

        while (tmp->next && tmp->value != value) {
            tmp2 = tmp;
            tmp = tmp->next;
        }

        // if node with target value at index 0 
        if ( list->value == tmp->value ) return list->next;

        if (tmp && tmp->value == value) {
            
            tmp2->next = tmp->next;
            free(tmp); 
        }
    }
    return list;
}



int main() {
    nNode *list = allocateNode(10, NULL, NULL);
    list->next = allocateNode(11, list, NULL);
    list->next->prev = list;

    printf(" * allocated nodes: %d %d ", list->value, list->next->value );
    /* expected output: * allocated nodes: 10 11 */

    printf(" \n Print Backwards Test \n   * print list: ");
    printBackwards(list);
    /* expected output: * print list: 11 10  */

    printf(" \n Print Test \n   * print list: ");
    print(list);
    /* expected output: * print list: 10 11  */

    insert(list, 5, 1);
    printf(" \n Inserted 5 at index 1 \n   * print list: ");
    print(list);
    /* expected output: * print list: 10 5 11  */

    printf(" \n Print Backwards Test \n   * print list: ");
    printBackwards(list);
    /* expected output: * print list: 11 5 10  */

    insertFirst(list, 1);
    printf(" \n InsertFirst 1 \n   * print list: ");
    print(list);
    /* expected output: * print list: 1 10 5 11  */

    insertLast(list, 20);
    printf(" \n InsertLast 20 \n   * print list: ");
    print(list);
    /* expected output: * print list: 1 10 5 11 20 */

    printf(" \n Print Backwards Test \n   * print list: ");
    printBackwards(list);
    /* expected output: * print list: 20 11 5 10 1 */

    int array[] = {0, 0, 0};
    insertLastFromArray(list, array, 3);
    printf(" \n InsertedLast From array \n   * print list: ");
    printBackwards(list);
    /* expected output: * print list: 0 0 0 20 11 5 10 1 */

    insertFirstFromArray(list, array, 3);
    printf(" \n InsertedFirst From array \n   * print list: ");
    printBackwards(list);
    /* expected output: * print list: 0 0 0 20 11 5 10 1 0 0 0 */

    delete(list, 5);
    printf(" \n deleted at index 5 \n   * print list: ");
    printBackwards(list);
    /* expected output: * print list: 0 0 0 20 11 10 1 0 0 0 */

}

/* TODO:
    make insert range, 0 < index < len
    add if list statement
    delete: check if index node exists 
    
*/