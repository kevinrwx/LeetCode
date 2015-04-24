
//Partition List

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

void printList(ListNode *l);

ListNode *partition(ListNode *head, int x)
{
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *lowDummy = new ListNode(-1);
    ListNode *highDummy = new ListNode(-1);
    ListNode *p = head;
    ListNode *lp = lowDummy;
    ListNode *hp = highDummy;
    while(p != NULL) {
        if(p->val < x) {
            lp->next = p;
            lp = lp->next;
        }
        else {
            hp->next = p;
            hp = hp->next;
        }
        p = p->next;
    }
    hp->next = NULL;    //
    lp->next = highDummy->next;
    return lowDummy->next;
}

void push(ListNode **head_ref, int new_data)
{
    ListNode *new_node = new ListNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
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

ListNode *createList(int arr[], int n)
{
    if(n == 0)
        return NULL;
    ListNode *p = new ListNode(arr[n-1]);
    for(int i = n-2; i >= 0; i--) {
        push(&p, arr[i]);
    }
    return p;
}

int main()
{
    int A[] = {1, 4, 3, 2, 5, 2};
    int n = sizeof(A)/sizeof(A[0]);
    int x = 3;
    ListNode *l = createList(A, n);
    printList(l);
    ListNode *par = partition(l, x);
    printList(par);
    return 0;
}
