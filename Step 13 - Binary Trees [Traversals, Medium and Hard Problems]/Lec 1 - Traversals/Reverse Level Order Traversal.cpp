/************************************************************

    Following is the TreeNode class structure:

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

#include <queue>
#include <vector>

// Reverse Array Function used here
void reverseArray(vector<int> & arr){
    int start = 0;
    int end = arr.size() - 1;
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

vector<int> reverseLevelOrder(TreeNode<int> *root){
    // Write your code here.
    //  Write your code here.
    if(root == NULL){
        return {};
    }

    queue<TreeNode<int>*> QueueContainer;
    vector<int> LevelOrderTraversal;
    QueueContainer.push(root);

    while(!QueueContainer.empty()){
        TreeNode<int> * currentNode = QueueContainer.front();
        QueueContainer.pop();

        LevelOrderTraversal.push_back(currentNode->val);

        if(currentNode-> left != NULL){
            QueueContainer.push(currentNode->left);
        }

        if(currentNode-> right != NULL){
            QueueContainer.push(currentNode->right);
        }
    }

    // Reverse the levelorder result to get Answer
    reverseArray(LevelOrderTraversal);
    return LevelOrderTraversal;
}