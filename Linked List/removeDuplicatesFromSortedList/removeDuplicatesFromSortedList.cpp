
//Remove Duplicates from Sorted List

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
	if(head == NULL)
		return NULL;
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* pNode = head;

	while(pNode->next != NULL) {
		if(pNode->val == pNode->next->val) {
			pNode->next = pNode->next->next;
		}
		else
			pNode = pNode->next;
	}
	return dummy->next;
}

ListNode* arrToList(int arr[], int n)
{
	ListNode* dummy = new ListNode(-1);
	ListNode* pNode = dummy;
	for(int i = 0; i < n; i++) {
		pNode->next = new ListNode(arr[i]);
		pNode = pNode->next;
	}
	return dummy->next;
}

void printList(ListNode* l)
{
	if(l == NULL)
		cout<<"Empty List"<<endl;
	ListNode* pNode = l;
	while(pNode != NULL) {
		cout<<pNode->val<<" ";
		pNode = pNode->next;
	}
	cout<<endl;
}

int main()
{
	int arr[] = {1, 2, 2, 3, 3, 4, 5, 6, 6, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	ListNode* l = arrToList(arr, n);
	printList(l);
	ListNode* res = deleteDuplicates(l);
	printList(res);
	return 0;
}



