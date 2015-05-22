
//Intersection of Two Linked Lists

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    if(headA == NULL || headB == NULL)
        return NULL;
    ListNode* pA = headA;
    ListNode* pB = headB;
    int countA = 0;
    int countB = 0;
    while(pA != NULL) {
        countA++;
        pA = pA->next;
    }
    while(pB != NULL) {
        countB++;
        pB = pB->next;
    }

    int diff = countA > countB ? (countA - countB) : (countB - countA);
    pA = headA;
    pB = headB;
    if(countA > countB) {
        while(diff > 0) {
            pA = pA->next;
            diff--;
        }
    }
    else {
        //
        while(diff > 0) {
            pB = pB->next;
            diff--;
        }
    }

    while(pA != NULL && pB != NULL) {
        if(pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        else
            return pA;
    }
    return NULL;
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

ListNode* createList(int arr[], int n)
{
    if(n == 0)
        return NULL;
    ListNode* dummy = new ListNode(-1);
    ListNode*p = dummy;
    for(int i = 0; i < n; i++) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    return dummy->next;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {9, 8, 7};
    int C[] = {6, 66, 666};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    int k = sizeof(C)/sizeof(C[0]);
    ListNode* headA = createList(A, n);
    ListNode* p = headA;
    ListNode* headB = createList(B, m);
    ListNode* q = headB;

    while(p->next != NULL)
        p = p->next;
    while(q->next != NULL)
        q = q->next;

    ListNode* headC = createList(C, k);
    p->next = headC;
    q->next = headC;
    cout<<"The List is: "<<endl;
    printList(headA);
    printList(headB);

    ListNode* result = getIntersectionNode(headA, headB);
    cout<<"The result is: "<<result->val;
    return 0;
}
