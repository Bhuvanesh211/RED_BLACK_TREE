#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    struct node *root = NULL;
    int choice, data;

    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Find Min\n5. Delete Min\n6. Find Max\n7. Delete Max\n8. Display Tree\n9. Inorder Traversal\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteNode(&root, data);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &data);
                struct node *result = search(root, data);
                if (result != NULL)
                    printf("Node with value %d found.\n", result->data);
                else
                    printf("Node not found.\n");
                break;
            case 4:
                {
                    struct node *minNode = findMin(root);
                    if (minNode != NULL)
                        printf("Minimum value: %d\n", minNode->data);
                    else
                        printf("Tree is empty.\n");
                }
                break;
            case 5:
                deleteMin(&root);
                printf("Minimum node deleted.\n");
                break;
            case 6:
                {
                    struct node *maxNode = findMax(root);
                    if (maxNode != NULL)
                        printf("Maximum value: %d\n", maxNode->data);
                    else
                        printf("Tree is empty.\n");
                }
                break;
            case 7:
                deleteMax(&root);
                printf("Maximum node deleted.\n");
                break;
            case 8:
                printf("Display Tree:\n");
                displayTree(root, 0);
                break;
            case 9:
                printf("Inorder Traversal:\n");
                inorder(root);
                printf("\n");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
