#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void avl_sorting(int data);
struct Node* insert(struct Node* node, int data);
struct Node* rightRotate(struct Node* y);
struct Node* leftRotate(struct Node* x);
int getHeight(struct Node* node);
int getBalance(struct Node* node);


void avl_sorting 
>>>>>>> 40f38d3 (teste)

// Structure of a node in AVL tree
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int main()
{
    int arr[] = {5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = NULL;

    // Insert all elements from the array into the AVL tree
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    // Print the AVL tree after sorting
    printf("AVL Tree after sorting: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}

// Function to perform in-order traversal and print the values
void inOrderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to insert a node into the AVL tree
struct Node* insert(struct Node* node, int data)
{
    // Step 1: Perform the normal BST insertion
    if (node == NULL)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else
    {
        return node;  // Duplicate data is not allowed
    }

    // Step 2: Update the height of the ancestor node
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    // Step 3: Get the balance factor of the node and balance the tree if necessary
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && data > node->right->data)
    {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Right rotate subtree rooted with y
struct Node* rightRotate(struct Node* y)
{
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Left rotate subtree rooted with x
struct Node* leftRotate(struct Node* x)
{
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

// Get the height of a node
int getHeight(struct Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// Get the balance factor of a node
int getBalance(struct Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
