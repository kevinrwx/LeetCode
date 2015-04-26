
//Rotate List

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head)
{
    if(head == NULL)
        cout<<"Empty List"<<endl;
    ListNode *p = head;
    while(p != NULL) {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

void push(ListNode **head, int data)
{
    ListNode *p = new ListNode(data);
    p->next = (*head);
    (*head) = p;
}

ListNode* createList(int arr[], int n)
{
    if(n == 0)
        return NULL;

//    ListNode *p = new ListNode(arr[n-1]);
//    for(int i = n-2; i >= 0; i--)
//        push(&p, arr[i]);
//    return p;

    ListNode *p = new ListNode(0);
    ListNode *dummy = p;
    for(int i = 0; i < n; i++) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    return dummy->next;
}


ListNode* rotateRight(ListNode *head, int k)
{
    if(head == NULL)
        return NULL;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p = head;
    ListNode *dummy2 = dummy;
    int n = 0;
    int m;
    while(p != NULL) {
        n++;
        p = p->next;
        dummy2 = dummy2->next;
    }
    ListNode *dummy1 = head;
    m = n - k - 1;
    while(m > 0) {
        dummy1 = dummy1->next;
        m--;
    }
    dummy->next = dummy1->next;
    dummy1->next = dummy2->next;
    dummy2->next = head;
    return dummy->next;
}


int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A)/sizeof(A[0]);
    ListNode *p = createList(A, n);
    cout<<"Before Rotate: "<<endl;
    printList(p);
    ListNode *q = rotateRight(p, 2);
    cout<<"After Rotate: "<<endl;
    printList(q);
    return 0;
}
