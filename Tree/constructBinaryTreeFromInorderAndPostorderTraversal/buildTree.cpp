
//Construct Binary Tree from Inorder and Postorder Traversal

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

TreeNode* buildOne(vector<int> &inorder, int istart, int iend, vector<int> &postorder, int pstart, int pend)
{
	if(pstart > pend)
		return NULL;
	TreeNode* root = new TreeNode(postorder[pend]);
	if(pstart == pend)
		return root;
	int i;
	for(i = 0; i < inorder.size(); i++)
		if(inorder[i+istart] == postorder[pend])
			break;
	root->left = buildOne(inorder, istart, istart+i-1, postorder, pstart, pstart+i-1);
	root->right = buildOne(inorder, istart+i+1, iend, postorder, pstart+i, pend-1);
	return root;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
{
	return buildOne(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}

vector<int> arrToVector(int nums[], int n)
{
	vector<int> results;
	for(int i = 0; i < n; i++)
		results.push_back(nums[i]);
	return results;
}

void printVector(vector<int> &tmp)
{
	int len = tmp.size();
	if(len == 0)
		cout<<"empty vetor";
	for(int i = 0; i < len; i++)
		cout<<tmp[i]<<" ";
	cout<<endl;
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
	int inNum[] = {9, 3, 15, 20, 7};
	int inN = sizeof(inNum) / sizeof(inNum[0]);
	vector<int> inorder;
	inorder = arrToVector(inNum, inN);

	int postNum[] = {9, 15, 7, 20, 3};
	int inP = sizeof(postNum) / sizeof(postNum[0]);
	vector<int> postorder;
	postorder = arrToVector(postNum, inP);

	TreeNode* root = buildTree(inorder, postorder);
	levelOrder(root);
	return 0;
}