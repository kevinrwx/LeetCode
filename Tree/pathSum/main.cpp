
//path sum

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int sum)
{
    if(root == NULL)
        return false;
    else {
        bool ba = false;
        int subSum = sum - root->val;
        if(subSum == 0 && root->left == NULL && root->right == NULL)
            return true;
        if(root->left != NULL)
            ba = ba || hasPathSum(root->left, subSum);
        if(root->right != NULL)
            ba = ba || hasPathSum(root->right, subSum);
        return ba;
    }

}


int main()
{
    int sum = 21;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);

    if(hasPathSum(root, sum))
        cout<<"There is a root to leaf path with sum "<<sum<<endl;
    else
        cout<<"There is no such a path "<<sum<<endl;
    return 0;
}
