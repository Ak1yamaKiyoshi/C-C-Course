#ifndef __single_linked_list_h__
#define __single_linked_list_h__



struct triangle {
    /* Properties 
     * A,B,C: x, y, lenght */
    int properties[3][3];
    /* COLOR: hexademical value */  
    int color; 
};

// Node structure
struct Node {
    struct triangle t; // Node value 
    struct Node *next; // Pointer to next element
} *head = NULL; // Head of list

typedef struct Node nNode;


#endif