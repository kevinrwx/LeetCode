
//Insertion Sort List

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertNext(ListNode* p, ListNode* node)
{
    if(p != NULL) {
        node->next = p->next;
        p->next = node;
    }
}

ListNode* findOne(ListNode* head, ListNode* node)
{
    ListNode* p = head;
    while((p->next != NULL) && (p->next->val <= node->val))
        p = p->next;
    return p;
}

ListNode* insertionSortList(ListNode* head)
{
    if(head == NULL)
        return NULL;
    ListNode* dummy = new ListNode(-1);
    ListNode* p = head;
    ListNode* sortedTmp;
    ListNode* tmp;
    while(p != NULL) {
        tmp = p;
        p = p->next;
        sortedTmp = findOne(dummy, tmp);
        insertNext(sortedTmp, tmp);
    }
    return dummy->next;
}

ListNode* creatList(int arr[], int n)
{
    if(n == 0)
        return NULL;
    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    for(int i = 0; i < n; i++) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    return dummy->next;
}

void printList(ListNode* head)
{
    if(head == NULL)
        cout<<"Empty List"<<endl;
    ListNode* p = head;
    while(p != NULL) {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}


int main()
{
    int A[] = {3, 4, 1, 2, 5};
    int n = sizeof(A)/sizeof(A[0]);
    ListNode* head = creatList(A, n);
    printList(head);
    ListNode* newHead = insertionSortList(head);
    printList(newHead);
    return 0;
}
