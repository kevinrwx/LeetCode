
//Delete Node in a Linked List

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
//这道题目的思路特别简单，但是由于题目并没有说的特别清楚，不知道node是指链表的头结点还是要删除的节点
//所以在刚开始思考的时候走了一些弯路
void deleteNode(ListNode* node) {
	if(node == NULL)
		return ;
	node->val = node->next->val;
	node->next = node->next->next;
}

int main() {
	//
}