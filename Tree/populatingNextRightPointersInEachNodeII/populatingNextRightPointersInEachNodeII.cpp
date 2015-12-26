
//Populating Next Right Pointers in Each Node II
//这道题目复用了Populating Next Right Pointers in Each Node的代码，而且不用进行任何更改
#include <iostream>
#include <stack>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode* left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode* root) {
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return ;
	stack<TreeLinkNode*> down;
	stack<TreeLinkNode*> up;
	up.push(root);
	while(!down.empty() || !up.empty()) {
		while(!up.empty()) {
			down.push(up.top());
			up.pop();
		}
		while(!down.empty()) {
			TreeLinkNode* tmp = down.top();
			down.pop();
			if(!down.empty())
				tmp->next = down.top();
			//注意点：在把tmp节点的左右子树push到stack中时，要提前先判断该节点的左右子树是否为空，不然的话，会报错
			if(tmp->left != NULL)
				up.push(tmp->left);
			if(tmp->right != NULL)
				up.push(tmp->right);
		}
	}
}

int main() {
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	connect(root);
	if(root->next != NULL) {
		cout<<root->next<<endl;
	}
	if(root->left->next != NULL) {
		cout<<root->left->next->val<<endl;
	}
	if(root->right->next != NULL) {
		cout<<root->right->next<<endl;
	}
	return 0;
}