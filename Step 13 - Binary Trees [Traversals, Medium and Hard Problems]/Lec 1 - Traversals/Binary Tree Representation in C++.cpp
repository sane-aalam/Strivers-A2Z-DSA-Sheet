/*
In C++, a binary tree can be represented in two primary ways:
1. Using Linked Structures (Nodes):
This is the most common representation ->
 Each node of the binary tree is a structure or class containing the following:
Data: The value stored in the node.
Left Pointer: Points to the left child node.
Right Pointer: Points to the right child node.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);

int tree[10] = {1, 2, 3, 4, 5}; // Example tree