
//Merge Two Sorted Lists 

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* dummy = new ListNode(-1);
	ListNode* pNode = dummy;
	ListNode* pNode1 = l1;
	ListNode* pNode2 = l2;
	if(pNode1 == NULL)
		return pNode2;
	if(pNode2 == NULL)
		return pNode1;

	while(pNode1 != NULL && pNode2 != NULL) {
		if(pNode1->val <= pNode2->val) {
			pNode->next = pNode1;
			pNode1 = pNode1->next;
			pNode = pNode->next;
		}
		else {
			pNode->next = pNode2;
			pNode2 = pNode2->next;
			pNode = pNode->next;
		}
	}
	if(pNode1 == NULL)
		pNode->next = pNode2;
	if(pNode2 == NULL)
		pNode->next = pNode1;
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
	ListNode* pNode = l;
	while(pNode != NULL) {
		cout<<pNode->val<<" ";
		pNode = pNode->next;
	}
	cout<<endl;
}


int main()
{
	int arr1[] = {1, 3, 5, 7, 9};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int arr2[] = {2, 4, 6, 8, 10};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	ListNode* l1 = arrToList(arr1, n1);
	ListNode* l2 = arrToList(arr2, n2);
	printList(l1);
	printList(l2);
	ListNode* l = mergeTwoLists(l1, l2);
	printList(l);
	return 0;

}