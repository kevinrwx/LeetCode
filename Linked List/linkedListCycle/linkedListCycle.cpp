
//Linked List Cycle

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
	if(head == NULL || head->next == NULL)
		return false;
	ListNode* pSlow = head;
	ListNode* pFast = head;
	//我刚开始写的判断条件是(pSlow->next != NULL && pFast->next->next != NULL)，但是对于数据量很大的情况下，程序会报runtime error
	//后来改成了(pFast->next != NULL && pFast->next->next != NULL)这个条件，程序就能正常运行了，不知道原因是甚么。。。
	while(pFast->next != NULL && pFast->next->next != NULL) {
		pSlow = pSlow->next;
		pFast = pFast->next->next;
		if(pSlow == pFast) {
			return true;
		}
	}
	return false;
}

int main() {
	ListNode* head = new ListNode(-1);
	head->next = new ListNode(1);
	// head->next->next = new ListNode(2);
	// head->next->next->next = new ListNode(3);
	// head->next->next->next->next = head->next;
	head->next->next = head->next;
	bool result = hasCycle(head);
	if(result)
		cout<<"has cycle";
	else
		cout<<"none";
	cout<<endl;
	return 0;
}




