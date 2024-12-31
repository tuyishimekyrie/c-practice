#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
// Function to create a new node
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}



void levelOrderTraversal(struct Node* root) {
	if (root == NULL) return;
	// Array-based queue
	struct Node* queue[100];
	int front = 0, rear = 0;
	// Add the root to the queue
	queue[rear++] = root;
	while (front < rear) {
    	struct Node* current = queue[front++]; // Dequeue the front element
    	printf("%d ", current->data);      	// Print the data
    	// Enqueue left child
    	if (current->left != NULL) {
        	queue[rear++] = current->left;
    	}
    	// Enqueue right child
    	if (current->right != NULL) {
        	queue[rear++] = current->right;
    	}
	}
}
int main() {
	// Create a simple binary tree
	struct Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);

	printf("Level Order Traversal: ");
	levelOrderTraversal(root);

	return 0;
}
