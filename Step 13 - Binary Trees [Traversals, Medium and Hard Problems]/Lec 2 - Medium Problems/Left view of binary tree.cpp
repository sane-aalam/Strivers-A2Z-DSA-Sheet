#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> * root, vector<int> & result, int level){
    if(root == nullptr){
        return;
    }
    if(result.size() == level){
        result.push_back(root->data);
    }
    solve(root->left,result,level+1);
    solve(root->right,result,level+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    int level = 0;
    vector<int> result;
    solve(root,result,level);
    return result;
}
