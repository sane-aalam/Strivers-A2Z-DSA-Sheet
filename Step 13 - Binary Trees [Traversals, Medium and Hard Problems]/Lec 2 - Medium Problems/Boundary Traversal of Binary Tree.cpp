
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

// 1. print the left side nodes without including the leaf node
// 2. print the all leaf node only
// 3. print the right side nodes without including the leaf node 

/*
 solution -
 
Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. 

The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
 */

class Solution {
private:
// step-1 Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node 
// you could reach when you always travel preferring the left subtree over the right subtree. 
   void preOrder(Node * root, vector<int> & bounaryTraversalResult){
       if(root == nullptr){
           return;
       }
       
       if(root->left == nullptr and root->right == nullptr){
           return;
       }

       bounaryTraversalResult.push_back(root->data);
       
       if(root->left != nullptr){
           preOrder(root->left,bounaryTraversalResult);
       }else{
           preOrder(root->right,bounaryTraversalResult);
       }
   }
   
 // step-2 Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary
   void OnlyLeafNodes(Node * root, vector<int> & bounaryTraversalResult){
       if(root == nullptr){
           return;
       }
       
       if(root->left == nullptr and root->right == nullptr){
           bounaryTraversalResult.push_back(root->data);
       }
      
        OnlyLeafNodes(root->left,bounaryTraversalResult);
        OnlyLeafNodes(root->right,bounaryTraversalResult);
   }
 
 // step-3 Right boundary nodes: defined as the path from the right-most node to the root.
   void postOrder(Node * root, vector<int> & bounaryTraversalResult){
       
       // base condtion 
       if(root == nullptr){
           return;
       }
       
        if(root->left == nullptr and root->right == nullptr){
           return;
       }
       
        // why we are taking root->right, because we gonna to right side first 
        //* Error Fix 
       if(root->right != nullptr){
           postOrder(root->right,bounaryTraversalResult);
       }else{
           postOrder(root->left,bounaryTraversalResult);
       }
       
       bounaryTraversalResult.push_back(root->data);
   }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> bounaryTraversalResult;
        
        // insert the root node (starting me hi)
        bounaryTraversalResult.push_back(root->data);
        
        preOrder(root->left,bounaryTraversalResult);
        
        OnlyLeafNodes(root->left,bounaryTraversalResult); // call for left side leaf node
        OnlyLeafNodes(root->right,bounaryTraversalResult); // call for right side leaf node 
        
        postOrder(root->right,bounaryTraversalResult);
        
        // return 1D- vector which have result of the binary tree
        return bounaryTraversalResult;
    }
};


// main function 
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}