
//Path Sum II

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> nodeToval(stack<TreeNode*> st)
{
	vector<int> results;
	stack<TreeNode*> wa;
	while(!st.empty()) {
		TreeNode* tmp = st.top();
		st.pop();
		wa.push(tmp);
	}
	while(!wa.empty()) {
		TreeNode* tmp = wa.top();
		wa.pop();
		results.push_back(tmp->val);
	}
	return results;
}

void backtrack(vector<vector<int> > &results, stack<TreeNode*> st, TreeNode* root, int sum)
{
	if(sum == 0 && root->left == NULL && root->right == NULL) {
		vector<int> tmp = nodeToval(st);
		results.push_back(tmp);
	}
	else {
		if(root->left != NULL) {
			st.push(root->left);
			backtrack(results, st, root->left, sum-root->left->val);
		}
		if(st.size() > 1 && root->left != NULL)
			st.pop();
		if(root->right != NULL) {
			st.push(root->right);
			backtrack(results, st, root->right, sum-root->right->val);
		}
	}
}

vector<vector<int> > pathSum(TreeNode* root, int sum)
{
	vector<vector<int> > results;
	if(root == NULL)
		return results;
	stack<TreeNode*> st;
	st.push(root);
	backtrack(results, st, root, sum-root->val);
	return results;
}

void printVector(vector<vector<int> > &results)
{
	int len = results.size();
	if(len == 0)
		cout<<"empty vector";
	else {
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < results[i].size(); j++)
				cout<<results[i][j]<<" ";
			cout<<endl;
		}
	}
	cout<<endl;
}

int main()
{
	TreeNode* root = new TreeNode(5);
	//root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	//root->left->left = new TreeNode(11);
	//root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	// root->left->left->left = new TreeNode(7);
	// root->left->left->right = new TreeNode(2);
	// root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(2);
	int sum = 19;
	vector<vector<int> > results = pathSum(root, sum);
	printVector(results);
	return 0;
}