
//Balanced binary tree

#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root)
{
	if(root == NULL)
		return 0;
	int heightL = height(root->left);
	int heightR = height(root->right);
	if(heightL > heightR)
		return heightL+1;
	else
		return heightR+1;
}

bool isBalanced(TreeNode* root)
{
	if(root == NULL)
		return true;
	int heightL = height(root->left);
	int heightR = height(root->right);
	if(abs(heightL - heightR) > 1) 
		return false;
	else {
		bool result = true;
		bool resultL = isBalanced(root->left);
		bool resultR = isBalanced(root->right);
		return (result && resultL && resultR);
	}
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->right->right = new TreeNode(3);
	root->left->left->left = new TreeNode(4);
	root->right->right->right = new TreeNode(4);
	bool is = isBalanced(root);
	if(is)
		cout<<"Balanced";
	else
		cout<<"Not Balanced";
	cout<<endl;
	return 0;
}