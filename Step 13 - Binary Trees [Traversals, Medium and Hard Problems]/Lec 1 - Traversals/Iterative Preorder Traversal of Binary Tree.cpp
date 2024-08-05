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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> preOrder;
        // member access within null pointer of type 'TreeNode'
        if(root == nullptr){
            return preOrder;
        }
        st.push(root);

        while(!st.empty()){
        // take stack top element, push into the result array
        // go to right direction of binary tree
        // go the left dirction of binary tree
        // stack degisn in this way - top element popped first
            TreeNode * temp = st.top();
            st.pop();

            preOrder.push_back(temp->val);

            if(temp->right != nullptr){
                st.push(temp->right);
            }
            if(temp->left != nullptr){
                st.push(temp->left);
            }
        }
        return preOrder;
    }
};