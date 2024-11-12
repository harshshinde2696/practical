#include <iostream>
using namespace std;
// Node structure for BST
struct Node {
int data;
Node* left;
Node* right;
Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Binary Search Tree Class
class BST {
private:
Node* root;
// Helper function to insert a node
Node* insert(Node* node, int key) {
if (node == nullptr) return new Node(key);
if (key < node->data) {
node->left = insert(node->left, key);
} else if (key > node->data) {
node->right = insert(node->right, key);
}
return node;
}
// Helper function to find the minimum value node in a subtree
Node* findMin(Node* node) {
while (node && node->left != nullptr) {
node = node->left;
}
return node;
}
// Helper function to delete a node
Node* deleteNode(Node* node, int key) {
if (node == nullptr) return node;
if (key < node->data) {
node->left = deleteNode(node->left, key);
} else if (key > node->data) {
node->right = deleteNode(node->right, key);
} else {
// Node with only one child or no child
if (node->left == nullptr) {
Node* temp = node->right;
delete node;
return temp;
} else if (node->right == nullptr) {
Node* temp = node->left;
delete node;
return temp;
}
// Node with two children: Get the inorder successor
Node* temp = findMin(node->right);
node->data = temp->data;
node->right = deleteNode(node->right, temp->data);
}
return node;
}
