
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
    if(k == 0)
        return head;

    ListNode *dummy_head = new ListNode(-1);
    dummy_head->next = head;
    ListNode *dummy_tail = dummy_head;
    ListNode *dummy_middle = dummy_head;
    int n = 0;
    int m;
    while(dummy_tail->next != NULL) {
        n++;
        dummy_tail = dummy_tail->next;
    }
    k = k % n;
    m = n - k;
    while(m > 0) {
        dummy_middle = dummy_middle->next;
        m--;
    }
    dummy_tail->next = dummy_head->next;
    dummy_head->next = dummy_middle->next;
    dummy_middle->next = NULL;
    return dummy_head->next;
}


int main()
{
    int A[] = {1, 2, 3, 4, 5};
//    int A[] = {1};
    int n = sizeof(A)/sizeof(A[0]);
    ListNode *p = createList(A, n);
    cout<<"Before Rotate: "<<endl;
    printList(p);
    ListNode *q = rotateRight(p, 2);
    cout<<"After Rotate: "<<endl;
    printList(q);
    return 0;
}

