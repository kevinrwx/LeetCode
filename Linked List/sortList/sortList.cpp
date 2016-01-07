
//Sort List

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//数组的快速排序代码，这个代码已经比较精简了，可以作为标准代码进行记忆了
void quickSort(vector<int>& nums, int left, int right) {
	if(left < right) {
		int i = left, j = right, tmp = nums[left];
		while(i < j) {
			while(i < j && nums[j] >= tmp)
				j--;
			if(i < j)
				nums[i++] = nums[j];
			while(i < j && nums[i] < tmp)
				i++;
			if(i < j)
				nums[j--] = nums[i];
		}
		nums[i] = tmp;
		quickSort(nums, left, i-1);
		quickSort(nums, i+1, right);
	}
}

void printList(ListNode* head) {
	if(head == NULL)
		cout<<"empty List";
	ListNode* pNode = head;
	while(pNode != NULL) {
		cout<<pNode->val<<" ";
		pNode = pNode->next;
	}
	cout<<endl;
}

//尝试使用快速排序的思想，但是下面的代码会报超时，具体原因不知道，还需要继续解决
// ListNode* sortList(ListNode* head) {
// 	if(head == NULL || head->next == NULL)
// 		return head;
// 	ListNode* pNode = head->next;
// 	int temp = head->val;
// 	ListNode* dummyLeft = new ListNode(-1);
// 	ListNode* dummyRight = new ListNode(-1);
// 	ListNode* tmp = NULL;
// 	while(pNode != NULL) {
// 		if(pNode->val < temp) {
// 			tmp = pNode;
// 			pNode = pNode->next;
// 			tmp->next = dummyLeft->next;
// 			dummyLeft->next = tmp;
// 		} else {
// 			tmp = pNode;
// 			pNode = pNode->next;
// 			tmp->next = dummyRight->next;
// 			dummyRight->next = tmp;
// 		}
// 	}
// 	ListNode* left = sortList(dummyLeft->next);
// 	ListNode* right = sortList(dummyRight->next);
// 	if(left == NULL){
// 		head->next = right;
// 		return head;
// 	}
// 	else {
// 		ListNode* qNode = left;
// 		while(qNode->next != NULL)
// 			qNode = qNode->next;
// 		qNode->next = head;
// 		qNode->next->next = right;
// 		return left;
// 	}
// }


//链表 归并排序，下面的代码是用归并的思想完成的，思路比较简单
ListNode* merge(ListNode* head1, ListNode* head2) {
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	ListNode* dummy = new ListNode(-1);
	ListNode* pNode = dummy;
	ListNode* pNode1 = head1;
	ListNode* pNode2 = head2;
	while(pNode1 != NULL && pNode2 != NULL) {
		if(pNode1->val < pNode2->val) {
			pNode->next = pNode1;
			pNode1 = pNode1->next;
		} else {
			pNode->next = pNode2;
			pNode2 = pNode2->next;
		}
		pNode = pNode->next;
	}
	if(pNode1 != NULL) {
		pNode->next = pNode1;
	} else if(pNode2 != NULL) {
		pNode->next = pNode2;
	}
	return dummy->next;
}

//这个版本的merge程序看起来更加简洁
// ListNode* merge(ListNode* head1, ListNode* head2) {
// 	if(head1 == NULL)
// 		return head2;
// 	if(head2 == NULL)
// 		return head1;
// 	ListNode* dummy = new ListNode(-1);
// 	ListNode* pNode = dummy;
// 	while(head1 != NULL && head2 != NULL) {
// 		if(head1->val < head2->val) {
// 			pNode->next = head1;
// 			head1 = head1->next;
// 		} else {
// 			pNode->next = head2;
// 			head2 = head2->next;
// 		}
// 		pNode = pNode->next;
// 	}
// 	if(head1 != NULL)
// 		pNode->next = head1;
// 	else if(head2 != NULL)
// 		pNode->next = head2;
// 	return dummy->next;
// }

ListNode* sortList(ListNode* head) {
	if(head == NULL || head->next == NULL)
		return head;
	ListNode* pSlow = head;
	ListNode* pFast = head;
	while(pFast->next != NULL && pFast->next->next != NULL) {
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}
	pFast = pSlow->next;
	pSlow->next = NULL;
	ListNode* pLeft = sortList(head);
	ListNode* pRight = sortList(pFast);
	return merge(pLeft, pRight);
}

int main() {
	ListNode* head = new ListNode(4);
	head->next = new ListNode(3);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(1);
	// printList(head);
	ListNode* res = sortList(head);
	printList(res);
	return 0;
}
