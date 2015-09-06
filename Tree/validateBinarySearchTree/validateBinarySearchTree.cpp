
//Validate Binary Search Tree

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//method I
//获取中序遍历的结果
// void inorderTraversal(TreeNode* root, vector<int> &travResult)
// {
// 	if(root != NULL) {
// 		inorderTraversal(root->left, travResult);
// 		travResult.push_back(root->val);
// 		inorderTraversal(root->right, travResult);
// 	}
// }

// bool isValidBST(TreeNode* root)
// {
// 	if(root == NULL)
// 		return true;
// 	vector<int> travResult;
// 	inorderTraversal(root, travResult);
// 	int length = travResult.size();
// 	for(int i = 1; i < length; i++) {
// 		if(travResult[i-1] >= travResult[i])
// 			return false;
// 	}
// 	return true;
// }

//Method II
//Method I方法的改进，可以不需要有保存所有的中序遍历结果
bool isValidBST(TreeNode* root)
{
	//
}

int main()
{
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	bool result = isValidBST(root);
	if(result)
		cout<<"BST"<<endl;
	else
		cout<<"Not BST"<<endl;
	return 0;
}