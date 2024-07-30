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
   void solve(TreeNode * root, vector<int> & PostorderTraversalContainer){
       if(root == nullptr){
        return;
       }
       solve(root->left, PostorderTraversalContainer);
       solve(root->right, PostorderTraversalContainer);
       PostorderTraversalContainer.push_back(root->val);
   }
public:
    vector<int> PostorderTraversal(TreeNode* root) {
        vector<int> PostorderTraversalContainer;
        solve(root,PostorderTraversalContainer);
        return PostorderTraversalContainer;
    }
};