#ifndef __node_c__
#define __node_c__

// node structure
struct node {
  struct node *left; // pointer to left chilf 
  struct node *right;// pointer to right chilf 
  int value; // node value 
};

typedef struct node nnode;

#endif 