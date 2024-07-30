/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void solve(BinaryTreeNode<int> * root, vector<int> & result,
 int level){

    if(root == nullptr){
        return;
    }

    if(result.size() == level){
        result.push_back(root->data);
    }

    solve(root->right,result,level+1);
    solve(root->left,result,level+1);
}

vector<int> printRightView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> result;
    int level = 0;
    solve(root,result,level);
    return result;
}