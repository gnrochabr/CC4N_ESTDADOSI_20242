#include <stdio.h>
#include <stdlib.h>

// Main function
int main()
{
    int arr[] = {5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n == 0)
    {
        printf("Empty array!\n");
        return 0;
    }

    struct Node* root = NULL;

    // Insert all elements from the array into the binary search tree
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    printf("Sorted array: ");
    inOrderTraversal(root);
    printf("\n");

    // Free memory after use
    destroyTree(root);

    return 0;
}

// Structure of a binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to traverse the tree in-order and print the values
void inOrderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to destroy the tree and free memory
void destroyTree(struct Node* root)
{
    if (root != NULL)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);  // Free memory of the node
    }
}
