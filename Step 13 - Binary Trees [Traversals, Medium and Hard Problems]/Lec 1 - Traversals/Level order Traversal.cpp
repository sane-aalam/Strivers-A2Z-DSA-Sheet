#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <queue>
#include <vector>

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(root == NULL){
        return {};
    }

    queue<BinaryTreeNode<int>*> QueueContainer;
    vector<int> LevelOrderTraversal;
    QueueContainer.push(root);

    while(!QueueContainer.empty()){
        BinaryTreeNode<int> * currentNode = QueueContainer.front();
        QueueContainer.pop();

        LevelOrderTraversal.push_back(currentNode->val);

        if(currentNode-> left != NULL){
            QueueContainer.push(currentNode->left);
        }

        if(currentNode-> right != NULL){
            QueueContainer.push(currentNode->right);
        }
    }

    return LevelOrderTraversal;
}
