#include <stdio.h>
#include <stdlib.h>

struct Node* insert(struct Node* root, int data); // Function declaration
struct Node* createNode(int data);
void inOrderTraversal(struct Node* root);
void destroyTree(struct Node* root);
void printTree(struct Node* root, int space);

#define COUNT 10

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

    printf("BST structure:\n");
    printTree(root, 0);

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

// Function to print the tree structure
void printTree(struct Node* root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    printTree(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}