#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* solve(vector<int> & arr, int start, int end){
    
    // base condtion 
    if(start > end){
        return NULL;
    }

    int mid = start+ (end-start)/2;
    TreeNode<int> * root = new TreeNode<int>(arr[mid]);

    // recusive call for left creation 
    root->left = solve(arr,start,mid-1);
    // recusive call for right creation 
    root->right = solve(arr,mid+1,end);
    return root;
}


TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    int start = 0;
    int end = n - 1;
    TreeNode<int>* root =  solve(arr,start,end);
    return root;
}