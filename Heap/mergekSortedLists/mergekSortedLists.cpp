
//Merge k Sorted Lists

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct MinHeap {
	vector<ListNode*> vec;
	int size;
	MinHeap(vector<ListNode*>& x, int y) : vec(x), size(y) {}
};

void swap(ListNode** x, ListNode** y) {
	ListNode* tmp = *x;
	*x = *y;
	*y = tmp;
}

void printList(ListNode* node) {
	if(node == NULL) {
		cout<<"empty lsit";
	} else {
		ListNode* pNode = node;
		while(pNode != NULL) {
			cout<<pNode->val<<" ";
			pNode = pNode->next;
		}
	}
	cout<<endl;
}

void printVec(MinHeap* minHeap) {
	if(minHeap->size <= 0)
		cout<<"empty heap";
	else {
		for(int i = 0; i < minHeap->size; i++)
			cout<<minHeap->vec[i]->val<<" ";
	}
	cout<<endl;
}

void MinHeapify(MinHeap* minHeap, int index) {
	int smallest = index;
	int left = (index << 1) + 1;
	int right = (index << 1) + 2;
	if(left < minHeap->size && minHeap->vec[left]->val < minHeap->vec[smallest]->val)
		smallest = left;
	if(right < minHeap->size && minHeap->vec[right]->val < minHeap->vec[smallest]->val)
		smallest = right;
	if(smallest != index) {
		swap(&minHeap->vec[smallest], &minHeap->vec[index]);
		MinHeapify(minHeap, smallest);
	}
}

MinHeap* buildAndCreateHeap(vector<ListNode*>& list) {
	int length = list.size();
	MinHeap* minHeap = new MinHeap(list, length);
	for(int i = (minHeap->size - 2)/2; i >= 0; i--)
		MinHeapify(minHeap, i);
	return minHeap;
}

ListNode* extractMin(MinHeap* minHeap) {
	if(minHeap->size <= 0)
		return NULL;
	else {
		ListNode* tmp = minHeap->vec[0];
		swap(&minHeap->vec[0], &minHeap->vec[minHeap->size-1]);
		minHeap->vec.pop_back();
		minHeap->size--;
		MinHeapify(minHeap, 0);
		return tmp;
	}
}

void insert(MinHeap* minHeap, ListNode* node) {
	minHeap->vec.push_back(node);
	minHeap->size++;
	int i = minHeap->size - 1;
	while(i != 0 && minHeap->vec[i]->val < minHeap->vec[(i-1)/2]->val) {
		swap(&minHeap->vec[i], &minHeap->vec[(i-1)/2]);
		i = (i-1)/2;
	}
}

//边界条件：[]、[[]]、[[][1]]、[[1][]]
ListNode* mergeKLists(vector<ListNode*>& lists) {
	int size = lists.size();
	if(size <= 0 || (size == 1 && lists[0] == NULL))
		return NULL;
	vector<ListNode*> myList;
	for(int i = 0; i < size; i++) {
		if(lists[i] != NULL)
			myList.push_back(lists[i]);
	}
	MinHeap* minHeap = buildAndCreateHeap(myList);
	ListNode* dummy = new ListNode(-1);
	ListNode* pNode = dummy;
	while(minHeap->size > 0) {
		pNode->next = extractMin(minHeap);
		pNode = pNode->next;
		ListNode* tmp = pNode->next;
		pNode->next = NULL;
		if(tmp != NULL)
			insert(minHeap, tmp);
	}
	return dummy->next;
}

int main() {
	ListNode* dummy1 = new ListNode(1);
	dummy1->next = new ListNode(4);
	dummy1->next->next = new ListNode(7);

	ListNode* dummy2 = new ListNode(2);
	dummy2->next = new ListNode(5);
	dummy2->next->next = new ListNode(8);

	ListNode* dummy3 = new ListNode(3);
	dummy3->next = new ListNode(6);
	dummy3->next->next = new ListNode(9);

	vector<ListNode*> lists;
	lists.push_back(dummy1);
	lists.push_back(dummy2);
	lists.push_back(dummy3);

	ListNode* result = mergeKLists(lists);
	printList(result);
	return 0;
}








