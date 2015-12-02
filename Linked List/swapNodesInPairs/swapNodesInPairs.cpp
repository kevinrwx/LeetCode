
//Swap Nodes in Pairs

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* prev = dummy;
	ListNode* cur = head;
	while(cur != NULL && cur->next != NULL) {
		prev->next = cur->next;
		cur->next = cur->next->next;
		prev->next->next = cur;
		prev = cur;
		cur = cur->next;
	}
	return dummy->next;
}

void printList(ListNode* head) {
	ListNode* p = head;
	while(p != NULL) {
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	printList(head);
	ListNode* result = swapPairs(head);
	printList(result);
	return 0;
}