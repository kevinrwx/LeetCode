
//Partition List

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *partition(ListNode *head, int x)
{
    if(head == NULL)
        return NULL;
    struct ListNode assist;
    assist.val = x-1;
    assist.next = head;
    ListNode *p = &assist;
    ListNode *pre = p;
    ListNode *cur = p->next;
    ListNode *index = p;

    while(cur != NULL) {
        if(cur->val < x) {
            pre->next = cur->next;
            cur->next = index->next;
            index->next = cur;
            cur = pre->next;
            index = index->next;
        }
        else {
            cur = cur->next;
            pre = pre->next;
        }
    }
    return p->next;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
