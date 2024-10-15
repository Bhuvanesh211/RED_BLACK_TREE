#ifndef MAIN_H
#define MAIN_H

// A Red-Black tree node structure
struct node {
    int data;
    char color;
    struct node *left, *right, *parent;
};

// Function declarations
void LeftRotate(struct node **root, struct node *x);
void rightRotate(struct node **root, struct node *y);
void insertFixUp(struct node **root, struct node *z);
void insert(struct node **root, int data);
void deleteNode(struct node **root, int data);
struct node *search(struct node *root, int data);
struct node *findMin(struct node *root);
struct node *findMax(struct node *root);
void deleteMin(struct node **root);
void deleteMax(struct node **root);
void inorder(struct node *root);
void displayTree(struct node *root, int space);

#endif // MAIN_H
