
//Reverse Linked List II

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
	if(head == NULL || m == n)
		return head;
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* pNode = dummy;
	int num = 0;
	while(pNode->next != NULL) {
		num++;
		if(num == m)
			break;
		pNode = pNode->next;
	}
	ListNode* mHead = pNode;
	pNode = pNode->next;
	ListNode* mTail = pNode;
	mHead->next = NULL;
	while(num <= n) {
		ListNode* tmp = pNode;
		pNode = pNode->next;
		num++;
		tmp->next = mHead->next;
		mHead->next = tmp;
	}
	mTail->next = pNode;
	return dummy->next;
}

void printList(ListNode* head) {
	if(head == NULL)
		cout<<"empty list";
	ListNode* pNode = head;
	while(pNode != NULL) {
		cout<<pNode->val<<" ";
		pNode = pNode->next;
	}
	cout<<endl;
}

int main() {
	ListNode* dummy = new ListNode(-1);
	dummy->next = new ListNode(1);
	ListNode* pNode = dummy->next;
	pNode->next = new ListNode(2);
	pNode = pNode->next;
	pNode->next = new ListNode(3);
	pNode = pNode->next;
	pNode->next = new ListNode(4);
	pNode = pNode->next;
	pNode->next = new ListNode(5);
	pNode = pNode->next;
	printList(dummy->next);
	int m = 2;
	int n = 4;
	ListNode* result = reverseBetween(dummy->next, m, n);
	printList(result);
	return 0;
}