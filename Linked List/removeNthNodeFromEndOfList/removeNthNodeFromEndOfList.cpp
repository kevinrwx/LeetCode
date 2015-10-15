
//Remove Nth Node From End of List

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//现在并没有想到更好的方法，只能用这种方法解决问题了
ListNode* removeNthFromEnd(ListNode* head, int n) {
	stack<ListNode*> st;
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* p = dummy;
	while(p != NULL) {
		st.push(p);
		p = p->next;
	}
	while(n-- > 0) {
		st.pop();
	}
	ListNode* tmp = st.top();
	tmp->next = tmp->next->next;
	return dummy->next;
}

void printList(ListNode* head) {
	if(head == NULL)
		cout<<"empty list";
	ListNode* p = head;
	while(p != NULL) {
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main() {
	int n = 5;
	ListNode* dummy;
	dummy->next = new ListNode(1);
	ListNode* ptr = dummy->next;
	for(int i = 2; i < 6; i++) {
		ptr->next = new ListNode(i);
		ptr = ptr->next;
	}
	printList(dummy->next);
	ListNode* result = removeNthFromEnd(dummy->next, n);
	printList(result);	
	return 0;
}

