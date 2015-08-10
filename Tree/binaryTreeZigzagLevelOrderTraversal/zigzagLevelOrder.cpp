//Recursive Way
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
		if(heightRight > heightLeft)
			return heightRight+1;
		else
			return heightLeft+1;
	}
}

void traversalGivenLevel(TreeNode* root, int level, bool flip, vector<int> &tmp)
{
	if(root == NULL)
		return;
	if(level == 1)
		tmp.push_back(root->val);
	else {
		if(flip) {
			traversalGivenLevel(root->left, level-1, flip, tmp);
			traversalGivenLevel(root->right, level-1, flip, tmp);
		}
		else {
			traversalGivenLevel(root->right, level-1, flip, tmp);
			traversalGivenLevel(root->left, level-1, flip, tmp);
		}
	}
}

vector<vector<int> > zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int> > results;
	if(root == NULL)
		return results;
	int height = getHeight(root);
	bool flip = true;
	for(int i = 1; i <= height; i++) {
		vector<int> tmp;
		traversalGivenLevel(root, i, flip, tmp);
		flip = !flip;
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
    results = zigzagLevelOrder(root);
    printVector(results);
	return 0;
}


//Iterative Way
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left; 
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int> > results;
	if(root == NULL)
		return results;
	stack<TreeNode*> ql;
	stack<TreeNode*> qr;
	ql.push(root);
	while(!ql.empty() || !qr.empty()) {
		vector<int> tmpL;
		while(!ql.empty()) {
			TreeNode* tmp = ql.top();
			ql.pop();
			tmpL.push_back(tmp->val);
			if(tmp->left != NULL)
				qr.push(tmp->left);
			if(tmp->right != NULL)
				qr.push(tmp->right);
		}
		if(tmpL.size() > 0)
			results.push_back(tmpL);

		vector<int> tmpR;
		while(!qr.empty()) {
			TreeNode* tmp = qr.top();
			qr.pop();
			tmpR.push_back(tmp->val);
			if(tmp->right != NULL)
				ql.push(tmp->right);
			if(tmp->left != NULL)
				ql.push(tmp->left);
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
	results = zigzagLevelOrder(root);
	printVector(results);
	return 0;
}
