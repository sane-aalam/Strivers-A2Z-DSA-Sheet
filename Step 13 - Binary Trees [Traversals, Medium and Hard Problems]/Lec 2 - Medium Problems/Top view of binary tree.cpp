/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h> 
using namespace std;

vector<int> getTopView(TreeNode<int> *root){
    // Write your code here.
     vector<int> ans;
        if(root == nullptr){
            return ans;
        }
    map <int, int> mapping;
    queue<pair<TreeNode<int>*,int >> q;
    
    q.push({root,0});
    
    while(!q.empty()){
        TreeNode <int> * temp = q.front().first;
        int horizontalDistance = q.front().second;
        q.pop();

        if(mapping.find(horizontalDistance) == mapping.end()){
             mapping[horizontalDistance] = temp->data;
        }

        if(temp ->left != nullptr){
            q.push({temp->left,horizontalDistance-1});
        }
        if(temp->right != nullptr){
            q.push({temp->right,horizontalDistance+1});
        }
    }

    // map <node*,int> 
    // map.first store node of binary tree
    // map.second store the result, we want !
    for(auto i:mapping){
          ans.push_back(i.second);
    }
    return ans; 
}
