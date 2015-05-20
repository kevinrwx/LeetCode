
//Minimum Depth of Binary Tree

#include <iostream>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root)
{
    int lDepth;
    int rDepth;
    int depth;
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right != NULL) {
            depth = minDepth(root->right) + 1;
    }
    else if(root->left != NULL && root->right == NULL) {
            depth = minDepth(root->left) + 1;
    }
    else if(root->left != NULL && root->right != NULL) {
        lDepth = minDepth(root->left);
        rDepth = minDepth(root->right);
        depth = lDepth < rDepth ? (lDepth + 1) : (rDepth + 1);
    }
    else {
        return 1;
    }
    return depth;
}

TreeNode* createBinaryTree(int arr[], int left, int right)
{
    if(left > right)
        return NULL;
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = createBinaryTree(arr, left, mid-1);
    root->right = createBinaryTree(arr, mid+1, right);
    return root;
}

void preOrder(TreeNode* root)
{
    if(root != NULL) {
        preOrder(root->left);
        cout<<root->val<<" ";
        preOrder(root->right);
    }
}

int main()
{
    int A[] = {1, 2};
    int n = sizeof(A)/sizeof(A[0]);
    TreeNode* root = createBinaryTree(A, 0, n-1);
    cout<<"The Tree is: ";
    preOrder(root);
    cout<<endl;
    int depth = minDepth(root);
    cout<<"Min Depth is: "<<depth<<endl;
    return 0;
}
