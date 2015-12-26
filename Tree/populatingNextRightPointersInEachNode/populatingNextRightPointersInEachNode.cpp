
//Populating Next Right Pointers in Each Node

#include <iostream>
#include <stack>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode* left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//主要的思路是使用两个额外的栈，down栈用来处理当前一层的节点，up栈用来存储下一层的节点
//每次在处理down栈的节点时，都先把该节点的左右子节点push到up栈中，然后再将该节点指向down栈的下一个元素(如果这个元素存在的话)
//将down栈的所有元素处理完毕以后，接着循环把up栈的元素再push到down栈中，接着进行下一轮的循环处理

/* 虽然这道题目解决了，但是并不满足题目中仅使用常数个空间的要求  */
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