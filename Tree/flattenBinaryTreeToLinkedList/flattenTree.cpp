
//Flatten Binary Tree to Linked List

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//比较不错的非递归遍历二叉树的方法，值得记忆
void preOrder(TreeNode* root)
{
	if(root == NULL)
		cout<<"empty tree";
	stack<TreeNode*> st;
	st.push(root);
	while(!st.empty()) {
		TreeNode* tmp = st.top();
		cout<<tmp->val<<" ";
		st.pop();
		if(tmp->right != NULL)
			st.push(tmp->right);
		if(tmp->left != NULL)
			st.push(tmp->left);
	}
}

//记得要将tmp->left和tmp->right设置为NULL，不然会报runtime error的错误
void flatten(TreeNode* root)
{
	if(root == NULL)
		return;
	stack<TreeNode*> st;
	st.push(root);
	TreeNode* dummy = new TreeNode(-1);
	TreeNode* p = dummy;
	while(!st.empty()) {
		TreeNode* tmp = st.top();
		st.pop();
		if(tmp->right != NULL)
			st.push(tmp->right);
		if(tmp->left != NULL)
			st.push(tmp->left);
		tmp->left = NULL;
		tmp->right = NULL;
		p->right = tmp;
		p = p->right;
	}
}

void printTree(TreeNode* root)
{
	if(root == NULL)
		cout<<"empty tree";
	TreeNode* tmp = root;
	while(tmp != NULL) {
		cout<<tmp->val<<" ";
		tmp = tmp->right;
	}
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(6);
	flatten(root);
	printTree(root);
	return 0;
}