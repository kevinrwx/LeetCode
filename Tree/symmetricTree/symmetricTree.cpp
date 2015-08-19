
//Symmetric Tree

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSame(TreeNode* rLeft, TreeNode* rRight)
{
	if(rLeft == NULL && rRight == NULL)
		return true;
	if((rLeft == NULL && rRight != NULL) || (rLeft != NULL && rRight == NULL) || (rLeft->val != rRight->val))
		return false;
	return isSame(rLeft->left, rRight->right) && isSame(rLeft->right, rRight->left);
}

bool isSymmetric(TreeNode* root)
{
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return true;

	return isSame(root->left, root->right);
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	//root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	//root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(4);
	bool result = isSymmetric(root);
	if(result)
		cout<<"Symmetric"<<endl;
	else
		cout<<"Not Symmetric"<<endl;
	return 0;
}