
//Reorder List

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
	if(head == NULL)
		cout<<"empty list"<<endl;
	ListNode* pNode = head;
	while(pNode != NULL) {
		cout<<pNode->val<<" ";
		pNode = pNode->next;
	}
	cout<<endl;
}

//这道题的思路比较清晰，通过快慢指针先找到链表的中间节点，然后将后半部分节点放入stack中，然后依次遍历前面的节点，
//将stack中弹出的节点插入pNode后面，这样就完成了reorder
void reorderList(ListNode* head) {
	if(head == NULL || head->next == NULL || head->next->next == NULL)
		return ;
	ListNode* pSlow = head;
	ListNode* pFast = head;
	while(pFast->next != NULL && pFast->next->next != NULL) {
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	ListNode* pNode = pSlow->next;
	pSlow->next = NULL;
	stack<ListNode*> st;
	while(pNode != NULL) {
		st.push(pNode);
		pNode = pNode->next;
	}
	pNode = head;
	while(pNode != NULL) {
		if(!st.empty()) {
			ListNode* tmp = st.top();
			st.pop();
			tmp->next = pNode->next;
			pNode->next = tmp;
			pNode = pNode->next->next;
		} else {
			pNode = pNode->next;
		}
	}
}

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	// head->next->next->next->next = new ListNode(5);
	printList(head);
	reorderList(head);
	return 0;
}