#define NODEC = 1;

struct node {
  struct node *left;
  struct node *right;
  int value;
};

typedef struct node nnode;