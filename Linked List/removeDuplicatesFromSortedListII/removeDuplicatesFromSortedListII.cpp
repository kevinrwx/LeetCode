
//Remove Duplicates from Sorted List II

//1252942084
//
//1748657699
//2721640133
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
	ListNode* preNode = dummy;
	ListNode* cur = NULL;
	//保证pNode不为空
	while(pNode != NULL && pNode->next != NULL) {
		if(pNode->val == pNode->next->val) {
			int tmp = pNode->val;
			cur = pNode;
			while(cur != NULL && cur->val == tmp) {
                cur = cur->next;
			}
			preNode->next = cur;
			pNode = cur;
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
