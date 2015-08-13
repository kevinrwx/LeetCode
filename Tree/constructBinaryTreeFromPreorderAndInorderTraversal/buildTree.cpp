

//Construct Binary Tree from Preorder and Inorder Traversal 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printVector(vector<int> &tmp)
{
	int len = tmp.size();
	if(len == 0)
		cout<<"empty vetor";
	for(int i = 0; i < len; i++)
		cout<<tmp[i]<<" ";
	cout<<endl;
}

TreeNode* buildOne(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int istart, int iend)
{
	if(pend < pstart)
		return NULL;
	TreeNode* root = new TreeNode(preorder[pstart]);
	if(pstart == pend)
		return root;
	int i;
	for(i = 0; i < inorder.size(); i++)
		if(inorder[i+istart] == preorder[pstart])
			break;
	root->left = buildOne(preorder, pstart+1, pstart+i, inorder, istart, istart+i-1);
	root->right = buildOne(preorder, pstart+i+1, pend, inorder, istart+i+1, iend);
	return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
{
	return buildOne(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

vector<int> arrToVector(int nums[], int n)
{
	vector<int> results;
	for(int i = 0; i < n; i++)
		results.push_back(nums[i]);
	return results;
}

void levelOrder(TreeNode* root)
{
	if(root == NULL)
		cout<<"empty tree";
	else {
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()) {
			TreeNode* tmp = q.front();
			q.pop();
			cout<<tmp->val<<" ";
			if(tmp->left != NULL)
				q.push(tmp->left);
			if(tmp->right != NULL)
				q.push(tmp->right);
		}
	}
}

int main()
{
	int preNum[] = {3, 9, 20, 15, 7};
	//int preNum[] = {9};
	int preN = sizeof(preNum) / sizeof(preNum[0]);
	vector<int> preorder;
	preorder = arrToVector(preNum, preN);

	int inNum[] = {9, 3, 15, 20, 7};
	//int inNum[] = {9};
	int inN = sizeof(inNum) / sizeof(inNum[0]);
	vector<int> inorder;
	inorder = arrToVector(inNum, inN);

	TreeNode* root = buildTree(preorder, inorder);
	levelOrder(root);

	return 0;

}