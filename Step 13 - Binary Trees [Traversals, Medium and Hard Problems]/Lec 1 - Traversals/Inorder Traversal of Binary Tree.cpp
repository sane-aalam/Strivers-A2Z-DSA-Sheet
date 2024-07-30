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
 */
class Solution {
private:
   void solve(TreeNode * root, vector<int> & preTraversalContainer){
       if(root == nullptr){
        return;
       }
       preTraversalContainer.push_back(root->val);
       solve(root->left, preTraversalContainer);
       solve(root->right, preTraversalContainer);
   }
public:
    vector<int> InorderTraversal(TreeNode* root) {
        vector<int> preTraversalContainer;
        solve(root,preTraversalContainer);
        return preTraversalContainer;
    }
};