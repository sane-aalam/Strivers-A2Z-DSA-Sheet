/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
 * Algorithm used here -> 
 * Process the left node 
 * Store the current-Node
 * Process the right node
 */

class Solution {
private:
   void solve(TreeNode * root, vector<int> & INOrderTraversalContainer){
       if(root == nullptr){
        return;
       }
       solve(root->left, INOrderTraversalContainer);
       INOrderTraversalContainer.push_back(root->val);
       solve(root->right, INOrderTraversalContainer);
   }
public:
    vector<int> InorderTraversal(TreeNode* root) {
        vector<int> INOrderTraversalContainer;
        solve(root,INOrderTraversalContainer);
        return INOrderTraversalContainer;
    }
};