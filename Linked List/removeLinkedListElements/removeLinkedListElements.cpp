
//Remove Linked List Elements

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//就按照正常思路来做就行了，没有什么需要注意的地方
ListNode* removeElements(ListNode* head, int val) {
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* pNode = dummy;
	while(pNode->next != NULL) {
		if(pNode->next->val == val) {
			pNode->next = pNode->next->next;
		} else {
			pNode = pNode->next;
		}
	}
	return dummy->next;
}

ListNode* arr2List(int arr[], int n) {
	ListNode* dummy = new ListNode(-1);
	ListNode* pNode = dummy;
	for(int i = 0; i < n; i++) {
		pNode->next = new ListNode(arr[i]);
		pNode = pNode->next;
	}
	return dummy->next;
}

void printList(ListNode* head) {
	ListNode* pNode = head;
	while(pNode != NULL) {
		cout<<pNode->val<<" ";
		pNode = pNode->next;
	}
	cout<<endl;
}

int main() {
	int nums[] = {1, 2, 6, 3, 4, 5, 6};
	int n = sizeof(nums) / sizeof(nums[0]);
	ListNode* head = arr2List(nums, n);
	printList(head);
	int val = 6;
	ListNode* newHead = removeElements(head, val);
	printList(newHead);
	return 0;
}