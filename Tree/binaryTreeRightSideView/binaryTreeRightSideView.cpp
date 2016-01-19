
//Binary Tree Right Side View

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

vector<int> rightSideView(TreeNode* root) {
	vector<int> result;
	if(root == NULL)
		return result;
	stack<TreeNode*> st;
	stack<TreeNode*> next;
	st.push(root);
	while(!st.empty()) {
		result.push_back(st.top()->val);
		while(!st.empty()) {
			TreeNode* tmp = st.top();
			st.pop();
			if(tmp->right != NULL)
				next.push(tmp->right);
			if(tmp->left != NULL)
				next.push(tmp->left);
		}
		while(!next.empty()) {
			st.push(next.top());
			next.pop();
		}
	}
	return result;
}

void printVector(vector<int>& nums) {
	int length = nums.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++)
		cout<<nums[i]<<" ";
	cout<<endl;
}

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(4);
	vector<int> result = rightSideView(root);
	printVector(result);
	return 0;
}