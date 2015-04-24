
//Add Two Numbers

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    int low = 0;
    int high = 0;
    int num;
    while(p1 != NULL && p2 != NULL) {
        num = p1->val + p2->val + high;
        if(num >= 10) {
            low = num - 10;
            high = (num - low) / 10;
        }
        else {
            low = num;
            high = 0;
        }
        p->next = new ListNode(low);
        p = p->next;
        p1 = p1->next;
        p2 = p2->next;
    }
    while(p1 != NULL) {
        num = p1->val + high;
        if(num >= 10) {
            low = num - 10;
            high = (num - low) / 10;
        }
        else {
            low = num;
            high = 0;
        }
        p->next = new ListNode(low);
        p = p->next;
        p1 = p1->next;
    }
    while(p2 != NULL) {
        num = p2->val + high;
        if(num >= 10) {
            low = num - 10;
            high = (num - low) / 10;
        }
        else {
            low = num;
            high = 0;
        }
        p->next = new ListNode(low);
        p = p->next;
        p2 = p2->next;
    }
    if(high != 0) {
        p->next = new ListNode(high);
        p = p->next;
    }
    return dummy->next;
}

void push(ListNode **head_ref, int new_data)
{
    ListNode *new_node = new ListNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

ListNode *createList(int arr[], int n)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *p = head;
    for(int i = 1; i < n; i++) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    return head;
}

ListNode *createList1(int arr[], int n)
{
    //
    if(n == 0)
        return NULL;
    ListNode *p = new ListNode(arr[n-1]);
    for(int i = n-2; i >= 0; i--) {
        push(&p, arr[i]);
    }
    return p;
}

void printList(ListNode *l)
{
    if(l == NULL)
        cout<<"Empty List"<<endl;
    ListNode *p = l;
    while(p != NULL) {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    //int A[] = {2, 4, 3};
    //int B[] = {5, 6, 4};
    int A[] = {5};
    int B[] = {5};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    ListNode *l1 = createList1(A, n);
    printList(l1);
    ListNode *l2 = createList1(B, m);
    printList(l2);

    ListNode *l = addTwoNumbers(l1, l2);
    printList(l);

    return 0;
}
