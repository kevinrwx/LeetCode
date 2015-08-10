
//Binary Tree Level Order Traversal 

//Method I
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode* root)
{
	if(root == NULL)
		return 0;
	else {
		int heightLeft = getHeight(root->left);
		int heightRight = getHeight(root->right);
		if(heightLeft >= heightRight)
			return heightLeft+1;
		else
			return heightRight+1;
	}
}

void printGivenLevel(TreeNode* root, int level, vector<int> &tmp)
{
	if(root == NULL)
		return;
	if(level == 1)
		tmp.push_back(root->val);
	else {
		printGivenLevel(root->left, level-1, tmp);
		printGivenLevel(root->right, level-1, tmp);
	}
}

vector<vector<int> > levelOrder(TreeNode* root) {
	vector<vector<int> > results;
	if(root == NULL)
		return results;
	int height = getHeight(root);
	for(int i = 1; i <= height; i++) {
		vector<int> tmp;
		printGivenLevel(root, i, tmp);
		results.push_back(tmp);
	}
	return results;
}


void printVector(vector<vector<int> > &results)
{
	int len = results.size();
	if(len == 0)
		cout<<"empty vector";
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < results[i].size(); j++)
			cout<<results[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	vector<vector<int> > results;
	results = levelOrder(root);
	printVector(results);
	return 0;
}



//Method II
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

vector<vector<int> > levelOrder(TreeNode* root)
{
	vector<vector<int> > results;
	if(root == NULL)
		return results;
	queue<TreeNode*> ql;
	queue<TreeNode*> qr;
	ql.push(root);
	while(!ql.empty() || !qr.empty()) {
		vector<int> tmpL;
		while(!ql.empty()) {
			TreeNode* tmpNode = ql.front();
			ql.pop();
			tmpL.push_back(tmpNode->val);
			if(tmpNode->left != NULL)
				qr.push(tmpNode->left);
			if(tmpNode->right != NULL)
				qr.push(tmpNode->right);
		}
		if(tmpL.size() > 0)
			results.push_back(tmpL);
		vector<int> tmpR;
		while(!qr.empty()) {
			TreeNode* tmpNode = qr.front();
			qr.pop();
			tmpR.push_back(tmpNode->val);
			if(tmpNode->left != NULL)
				ql.push(tmpNode->left);
			if(tmpNode->right != NULL)
				ql.push(tmpNode->right);
		}
		if(tmpR.size() > 0)
			results.push_back(tmpR);
	}
	return results;
}

void printVector(vector<vector<int> > &results)
{
	int len = results.size();
	if(len == 0)
		cout<<"empty vector";
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < results[i].size(); j++)
			cout<<results[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	vector<vector<int> > results;
	results = levelOrder(root);
	printVector(results);
	return 0;
}
