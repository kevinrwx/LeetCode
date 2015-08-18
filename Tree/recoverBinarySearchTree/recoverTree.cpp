
//Recover Binary Search Tree

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//参考资料：http://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/
void recoverBSTUtil(TreeNode* root, TreeNode** first, TreeNode** middle, TreeNode** last, TreeNode** prev)
{
	if(root != NULL) {
		recoverBSTUtil(root->left, first, middle, last, prev);
		if(*prev != NULL && root->val < (*prev)->val) {
			if(*first == NULL) {
				*first = *prev;
				*middle = root;
			}
			else
				*last = root;
		}
		*prev = root;
		recoverBSTUtil(root->right, first, middle, last, prev);
	}
}

void recoverTree(TreeNode* root)
{
	TreeNode* first = NULL;
	TreeNode* middle = NULL;
	TreeNode* last = NULL;
	TreeNode* prev = NULL;
	recoverBSTUtil(root, &first, &middle, &last, &prev);
	if(first != NULL && last != NULL)
		swap(&(first->val), &(last->val));
	else if(first != NULL && middle != NULL)
		swap(&(first->val), &(middle->val));
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
	cout<<endl;
}

int main()
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(4);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(7);
	levelOrder(root);
	recoverTree(root);
	levelOrder(root);
	return 0;
}