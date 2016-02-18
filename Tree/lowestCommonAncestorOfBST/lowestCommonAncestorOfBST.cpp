
//Lowest Common Ancestor of a Binary Search Tree

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//这道题的思路还是比较清晰的，就是从根节点往下找就行了，然后比较p、q和root节点的大小
//总共分为5种情况：
//1、root == p 或 root ==  q
//2、root < p 且 root < q
//3、root > p 且 root > q
//4、root < p 且 root > q
//5、root > p 且 root < q
//4和5两种情况可以归结为一种
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root == NULL || p == NULL || q == NULL)
		return NULL;
	if(root == p || root == q)
		return root;
	else if(root->val < p->val && root->val < q->val) {
		return lowestCommonAncestor(root->right, p, q);
	} else if(root->val > p->val && root->val > q->val){
		return lowestCommonAncestor(root->left, p, q);
	} else {
		return root;
	}
}

int main() {
	TreeNode* root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);
	TreeNode* lca = lowestCommonAncestor(root, root->left, root->left->right);
	cout<<"lca: "<<lca->val<<endl;
	return 0;
}