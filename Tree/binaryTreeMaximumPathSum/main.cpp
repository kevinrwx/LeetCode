 
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

//下面的这种方法没有考虑到节点值为负数的情况
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
    cout<<"The Result is: "<<result<<endl;
    return 0;
}
