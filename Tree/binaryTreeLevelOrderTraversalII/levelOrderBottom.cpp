
//Binary Tree Level Order Traversal II 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode* root)
{
	vector<vector<int> > results;
	if(root == NULL)
		return results;
	queue<TreeNode*> ql;
	queue<TreeNode*> qr;
	stack<vector<int> > st;
	ql.push(root);
	while(!ql.empty() || !qr.empty()) {
		vector<int> tmpL;
		while(!ql.empty()) {
			TreeNode* tmp = ql.front();
			ql.pop();
			tmpL.push_back(tmp->val);
			if(tmp->left != NULL)
				qr.push(tmp->left);
			if(tmp->right != NULL)
				qr.push(tmp->right);
		}
		if(tmpL.size() > 0)
			st.push(tmpL);

		vector<int> tmpR;
		while(!qr.empty()) {
			TreeNode* tmp = qr.front();
			qr.pop();
			tmpR.push_back(tmp->val);
			if(tmp->left != NULL)
				ql.push(tmp->left);
			if(tmp->right != NULL)
				ql.push(tmp->right);
		}
		if(tmpR.size() > 0)
			st.push(tmpR);
	}
	while(!st.empty()) {
		results.push_back(st.top());
		st.pop();
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
	results = levelOrderBottom(root);
	printVector(results);
	return 0;
}









