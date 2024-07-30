/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void PreOrderTraversal(TreeNode *root, vector<int>& result) {

    if (root == nullptr) 
     return;

    result.push_back(root->data);
    PreOrderTraversal(root->left, result);
    PreOrderTraversal(root->right, result);

}
 
void PostOrderTraversal(TreeNode *root, vector<int>& result) {

    if (root == nullptr) return;

    PostOrderTraversal(root->left, result);
    PostOrderTraversal(root->right, result);
    result.push_back(root->data);
}

void InOrderTraversal(TreeNode *root, vector<int>& result) {

    if (root == nullptr) return;

    InOrderTraversal(root->left, result);
    result.push_back(root->data);
    InOrderTraversal(root->right, result);
}

 
vector<vector<int>> getTreeTraversal(TreeNode *root) {

    vector<vector<int>> traversals(3); // To store PreOrder, InOrderTraversal, and PostOrderTraversal

    InOrderTraversal(root, traversals[0]);
    PreOrderTraversal(root, traversals[1]);
    PostOrderTraversal(root, traversals[2]);
    return traversals;
}