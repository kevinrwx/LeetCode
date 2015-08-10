
//same tree

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
	if(p == NULL && q == NULL)
		return true;
	else if(p == NULL && q != NULL) {
		return false;
	}
	else if(p != NULL && q == NULL) {
		return false;
	}
	else {
		bool sameL = isSameTree(p->left, q->left);
		bool sameR = isSameTree(p->right, q->right);
		if((p->val == q->val) && sameL && sameR)
			return true;
		else
			return false;
	}
}

int main()
{
	TreeNode* p = new TreeNode(3);
	p->left = new TreeNode(7);
	p->right = new TreeNode(20);

	TreeNode*q = new TreeNode(3);
	q->left = new TreeNode(9);
	q->right = new TreeNode(20);

	TreeNode* r = NULL;
	TreeNode* s = NULL;
	if(isSameTree(p, s))
		cout<<"Same Tree"<<endl;
	else
		cout<<"Not Same"<<endl;
	return 0;
}