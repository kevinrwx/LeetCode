
// Kth Smallest Element in a BST

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//这种方法需要计算二叉树的节点个数，因此复杂度比较高
// int calculateTreeSize(TreeNode* root) {
// 	if(root == NULL)
// 		return 0;
// 	return 1 + calculateTreeSize(root->left) + calculateTreeSize(root->right);
// }

// int kthSmallest(TreeNode* root, int k) {
// 	if(root == NULL)
// 		return 0;
// 	int leftSize = calculateTreeSize(root->left);
// 	if(leftSize + 1 == k) {
// 		return root->val;
// 	} else if(k <= leftSize) {
// 		return kthSmallest(root->left, k);
// 	} else {
// 		return kthSmallest(root->right, k-leftSize-1);
// 	}
// }

//利用二叉树非递归中序遍历的思想，但是这种解法还不是完全按照非递归的代码进行模仿的
// int kthSmallest(TreeNode* root, int k) {
// 	if(root == NULL)
// 		return 0;
// 	stack<TreeNode*> st;
// 	TreeNode* pNode = root;
// 	while(pNode != NULL) {
// 		st.push(pNode);
// 		pNode = pNode->left;
// 	}
// 	while(k > 0 && (pNode != NULL || !st.empty())) {
// 		if(!st.empty()) {
// 			pNode = st.top();
// 			st.pop();
// 			if(--k == 0)
// 				return pNode->val;
// 			pNode = pNode->right;
// 		}
// 		while(pNode != NULL) {
// 			st.push(pNode);
// 			pNode = pNode->left;
// 		}
// 	}
// }

//这种解法是完全按照非递归的思路进行解决的
int kthSmallest(TreeNode* root, int k) {
	if(root == NULL)
		return 0;
	stack<TreeNode*> st;
	TreeNode* pNode = root;
	while(k > 0 && (pNode != NULL || !st.empty())) {
		while(pNode != NULL) {
			st.push(pNode);
			pNode = pNode->left;
		}
		if(!st.empty()) {
			pNode = st.top();
			st.pop();
			if(--k == 0)
				return pNode->val;
			pNode = pNode->right;
		}
	}
}

//二叉树非递归中序遍历代码
void inorderTraversal1(TreeNode* root) {
	if(root == NULL)
		cout<<"empty tree"<<endl;
	stack<TreeNode*> st;
	TreeNode* pNode = root;
	while(pNode != NULL || !st.empty()) {
		while(pNode != NULL) {
			st.push(pNode);
			pNode = pNode->left;
		}
		if(!st.empty()) {
			pNode = st.top();
			st.pop();
			cout<<pNode->val<<" ";
			pNode = pNode->right;
		}
	}
}

void inorderTraversal(TreeNode* root) {
	if(root != NULL) {
		inorderTraversal(root->left);
		cout<<root->val<<" ";
		inorderTraversal(root->right);
	}
}

int main() {
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(7);
	inorderTraversal1(root);
	return 0;
}