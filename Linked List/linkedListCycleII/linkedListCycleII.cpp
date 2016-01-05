
//linked list cycle II

#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//这种方法的思路比较简单，就是用一个set存放节点的指针，如果存在环的话，第一次遇到重复节点时，该节点就是环的起点
//如果不存在环，那么result就是默认的NULL，所以最后返回NULL就可以了
//不过这种方法不满足题目要求的不能使用额外的存储空间的要求
// ListNode* detectCycle(ListNode* head) {
// 	if(head == NULL || head->next == NULL)
// 		return NULL;
// 	unordered_set<ListNode*> node;
// 	ListNode* pNode = head;
// 	ListNode* result = NULL;
// 	while(pNode != NULL) {
// 		if(node.find(pNode) == node.end()) {
// 			node.insert(pNode);
// 		} else {
// 			result = pNode;
// 			break;
// 		}
// 		pNode = pNode->next;
// 	}
// 	return result;
// }

//第二种方法能满足题目的不使用额外的存储空间的要求
//该方法分为两个步骤，如果存在环的话，先找出pFast和pSlow第一次相遇的节点，并将该节点记录下来
//第二步就是寻找两个链表的第一个公共节点，方法是先遍历求出两个链表的长度，然后再从较长的链表遍
//历掉这两个链表差值长度的节点，接着在同时在两个链表上遍历，找到第一个相同的节点就是他们的公共
//节点
ListNode* detectCycle(ListNode* head) {
	if(head == NULL || head->next == NULL)
		return NULL;
	ListNode* pSlow = head;
	ListNode* pFast = head;
	ListNode* result = NULL;
	bool cycle = false;
	//如果有环的话，求出pFast和pSlow相遇的第一个节点，这个节点肯定在环内
	while(pFast->next != NULL && pFast->next->next != NULL) {
		pSlow = pSlow->next;
		pFast = pFast->next->next;
		if(pSlow == pFast) {
			cycle = true;
			break;
		}
	}
	//如果有环的话，这道题目就变成了寻找两个链表的第一个公共节点的问题，解决该问题的方法在上面的注释中已经做了说明
	if(cycle) {
		ListNode* pNode1 = head;
		ListNode* pNode2 = pFast->next;
		int num1, num2;
		num1 = num2 = 0;
		while(pNode1 != pFast) {
			num1++;
			pNode1 = pNode1->next;
		}
		while(pNode2 != pFast) {
			num2++;
			pNode2 = pNode2->next;
		}
		int balance = (num1 > num2) ? (num1 - num2) : (num2 - num1);
		ListNode* pNode = (num1 > num2) ? head : pFast->next;
		ListNode* qNode = (num1 > num2) ? pFast->next : head;
		while(balance > 0) {
			pNode = pNode->next;
			balance--;
		}
		while(pNode != qNode) {
			pNode = pNode->next;
			qNode = qNode->next;
		}
		result = pNode;
	}
	return result;
}

int main() {
	ListNode* head = new ListNode(-1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = head->next;
	// head->next->next = head->next;
	ListNode* result = detectCycle(head);
	if(result != NULL)
		cout<<result->val<<endl;
	else
		cout<<"haha"<<endl;
	return 0;
}