
//Copy List with Random Pointer

#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//该题的思路是用map存放已经复制过的节点，所以每次复制节点时都要先从map中查询一下，看看有没有已经复制过的节点，如果有，则直接使用，如果没有再复制节点，并把复制后的节点存入map
RandomListNode* copyRandomList(RandomListNode* head) {
	if(head == NULL)
		return NULL;
	//该map的key是原RandomListNode的节点,value是复制后的RandomListNode的节点
	map<RandomListNode*, RandomListNode*> myMap;
	RandomListNode* dummy = new RandomListNode(-1);
	RandomListNode* pNode = head;
	RandomListNode* cNode = dummy;
	while(pNode != NULL) {
		if(myMap.find(pNode) == myMap.end()) {
			cNode->next = new RandomListNode(pNode->label);
			myMap.insert(pair<RandomListNode*, RandomListNode*>(pNode, cNode->next));
		} else {
			cNode->next = myMap[pNode];
		}
		if(pNode->random != NULL) {
			if(myMap.find(pNode->random) == myMap.end()) {
				cNode->next->random = new RandomListNode(pNode->random->label);
				myMap.insert(pair<RandomListNode*, RandomListNode*>(pNode->random, cNode->next->random));
			} else {
				cNode->next->random = myMap[pNode->random];
			}
		}
		cNode = cNode->next;
		pNode = pNode->next;
	}
	return dummy->next;
}

void printList(RandomListNode* head) {
	RandomListNode* pNode = head;
	while(pNode != NULL) {
		cout<<pNode->label<<" ";
		pNode = pNode->next;
	}
	cout<<endl;
}

int main() {
	RandomListNode* dummy = new RandomListNode(-1);
	dummy->next = new RandomListNode(1);
	dummy->next->next = new RandomListNode(1);
	RandomListNode* result = copyRandomList(dummy->next);
	printList(result);
	return 0;
}