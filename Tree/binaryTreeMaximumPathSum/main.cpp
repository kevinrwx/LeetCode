
//Binary Tree Maximum Path Sum

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//树的节点值可能为负数

int maxTreeSum(TreeNode* root)
{
    if(root == NULL)
        return 0;
    int leftVal = maxTreeSum(root->left);
    int rightVal = maxTreeSum(root->right);
    return root->val + (leftVal > rightVal ? leftVal : rightVal);
}

int maxPathSum(TreeNode* root)
{
    if(root == NULL)
        return 0;
    int leftSum = maxTreeSum(root->left);
    int rightSum = maxTreeSum(root->right);
    int sum = leftSum + rightSum + root->val;
    return sum;
}


int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);

    int result = maxPathSum(root);
    cout<<"The Result is: "<<result;
    return 0;
}
