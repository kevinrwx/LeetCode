
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
    if(l1 == NULL || l2 == NULL)
        return NULL;
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    while(l1 != NULL && l2 != NULL) {
        ////
    }
}


int main()
{
    ListNode *p = new ListNode(0);
    cout<<p->val;
    return 0;
}
