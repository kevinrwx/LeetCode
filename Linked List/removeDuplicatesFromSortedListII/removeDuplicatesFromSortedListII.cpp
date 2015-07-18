
//Remove Duplicates from Sorted List II

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicatesI(ListNode* head)
{
	if(head == NULL)
		return NULL;
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* pNode = dummy;
	ListNode* cur = NULL;
	while(pNode->next->next != NULL) {
		if(pNode->next->val == pNode->next->next->val) {
			cur = pNode->next;
			while(cur->val == cur->next->val) {
				cur->next = cur->next->next;
			}
			pNode->next = pNode->next->next;
		}
		if(pNode->next->next != NULL)
			pNode = pNode->next;
		else {
			cout<<pNode->val<<endl;
			return pNode->next;
		}
			//return pNode->next;
	}
	return dummy->next;
}

ListNode* deleteDuplicates(ListNode* head)
{
	if(head == NULL)
		return NULL;
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* pNode = head;
	ListNode* preNode = dummy;
	ListNode* cur = NULL;
	while(pNode->next != NULL) {
		if(pNode->val == pNode->next->val) {
			cur = pNode;
			while(cur->val == cur->next->val)
				cur->next = cur->next->next;
			//pNode = pNode->next;
			preNode->next = cur->next;
			pNode = preNode->next;
		}
		else {
			pNode = pNode->next;
			preNode = preNode->next;
		}
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
	//int arr[] = {1, 2, 3, 3, 4 ,5};
	int arr[] = {1, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	ListNode* l = arrToList(arr, n);
	ListNode* res = deleteDuplicates(l);
	printList(res);
	return 0;
}
