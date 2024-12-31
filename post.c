#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototypes
Node* createNode(int data);
void postOrderTraversal(Node* root);
void freeTree(Node* root);

int main() {
    // Manually creating a binary tree for demonstration
    // Tree structure:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Postorder Traversal (Left-Right-Node): ");
    postOrderTraversal(root);
    printf("\n");

    // Free memory
    freeTree(root);
    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for postorder traversal (left-right-node)
void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    postOrderTraversal(root->left);

    // Traverse the right subtree
    postOrderTraversal(root->right);

    // Visit the root
    printf("%d ", root->data);
}

// Function to free memory allocated for the tree
void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }

    // Free left and right subtrees
    freeTree(root->left);
    freeTree(root->right);

    // Free the current node
    free(root);
}
