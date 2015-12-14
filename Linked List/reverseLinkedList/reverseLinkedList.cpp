
//Reverse Linked List

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
	if(head == NULL)
		return head;
	ListNode* dummy = new ListNode(-1);
	ListNode* pNode = head;
	while(pNode != NULL) {
		ListNode* tmpNode = pNode;
		pNode = pNode->next;
		tmpNode->next = dummy->next;
		dummy->next = tmpNode;
	}
	return dummy->next;
}

void printList(ListNode* head) {
	ListNode* pNode = head;
	if(pNode == NULL)
		cout<<"empty list"<<endl;
	while(pNode != NULL) {
		cout<<pNode->val<<" ";
		pNode = pNode->next;
	}
	cout<<endl;
}

int main() {
	//
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	printList(head);
	ListNode* result = reverseList(head);
	printList(result);
	return 0;
}