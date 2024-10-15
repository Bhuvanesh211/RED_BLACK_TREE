#include "main.h"
#include <stdio.h>
#include <stdlib.h>

// Left Rotation
void LeftRotate(struct node **root, struct node *x) {
    if (!x || !x->right)
        return;

    struct node *y = x->right;
    x->right = y->left;

    if (x->right != NULL)
        x->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        (*root) = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Right Rotation
void rightRotate(struct node **root, struct node *y) {
    if (!y || !y->left)
        return;

    struct node *x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (x->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Utility function to fixup the Red-Black tree after standard BST insertion
void insertFixUp(struct node **root, struct node *z) {
    while (z != *root && z->parent->color == 'R') {
        struct node *y;
        if (z->parent == z->parent->parent->left)
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;

        if (y && y->color == 'R') {
            y->color = 'B';
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
        } else {
            if (z->parent == z->parent->parent->left && z == z->parent->left) {
                char ch = z->parent->color;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root, z->parent->parent);
            } else if (z->parent == z->parent->parent->left && z == z->parent->right) {
                char ch = z->color;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root, z->parent);
                rightRotate(root, z->parent->parent);
            } else if (z->parent == z->parent->parent->right && z == z->parent->right) {
                char ch = z->parent->color;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root, z->parent->parent);
            } else if (z->parent == z->parent->parent->right && z == z->parent->left) {
                char ch = z->color;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root, z->parent);
                LeftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = 'B';
}

// Utility function to insert a new node into the Red-Black tree
void insert(struct node **root, int data) {
    struct node *z = (struct node*)malloc(sizeof(struct node));
    z->data = data;
    z->left = z->right = z->parent = NULL;

    if (*root == NULL) {
        z->color = 'B';
        (*root) = z;
    } else {
        struct node *y = NULL;
        struct node *x = (*root);

        while (x != NULL) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;
        if (z->data > y->data)
            y->right = z;
        else
            y->left = z;

        z->color = 'R';
        insertFixUp(root, z);
    }
}

// Inorder traversal function
void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to display the tree structure
void displayTree(struct node *root, int space) {
    if (root == NULL)
        return;

    int count = 5;
    space += count;

    displayTree(root->right, space);

    printf("\n");
    for (int i = count; i < space; i++)
        printf(" ");
    printf("%d (%c)\n", root->data, root->color);

    displayTree(root->left, space);
}

// Search function
struct node *search(struct node *root, int data) {
    while (root != NULL) {
        if (data == root->data)
            return root;
        else if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// Find minimum node
struct node *findMin(struct node *root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Find maximum node
struct node *findMax(struct node *root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to delete the minimum node
void deleteMin(struct node **root) {
    struct node *minNode = findMin(*root);
    deleteNode(root, minNode->data);
}

// Function to delete the maximum node
void deleteMax(struct node **root) {
    struct node *maxNode = findMax(*root);
    deleteNode(root, maxNode->data);
}

// Function to delete a node
void deleteNode(struct node **root, int data) {
    struct node *z = search(*root, data);
    if (z == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    struct node *y = z; // Node to be deleted
    struct node *x; // Child of y

    char originalColor = y->color;

    if (z->left == NULL) {
        x = z->right;
        if (x != NULL) x->parent = z->parent;
        if (z->parent == NULL)
            (*root) = z->right; // z is root
        else if (z == z->parent->left)
            z->parent->left = z->right;
        else
            z->parent->right = z->right;
    } else if (z->right == NULL) {
        x = z->left;
        if (x != NULL) x->parent = z->parent;
        if (z->parent == NULL)
            (*root) = z->left; // z is root
        else if (z == z->parent->left)
            z->parent->left = z->left;
        else
            z->parent->right = z->left;
    } else {
        y = findMin(z->right); // Find the successor
        originalColor = y->color;
        x = y->right; // y's right child

        if (y->parent == z) {
            if (x != NULL) x->parent = y;
        } else {
            if (x != NULL) x->parent = y->parent;
            y->parent->left = x; // Replace y with its child
            y->right = z->right; // Link z's right child to y
            y->right->parent = y;
        }

        if (z->parent == NULL)
            (*root) = y; // z is root
        else if (z == z->parent->left)
            z->parent->left = y;
        else
            z->parent->right = y;

        y->left = z->left; // Link z's left child to y
        y->left->parent = y;
        y->color = z->color; // Copy the color
    }

    free(z); // Free memory

    if (originalColor == 'B')
        ; // Fixup logic if needed here
}
