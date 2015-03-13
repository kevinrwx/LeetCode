
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
    ListNode *p = head;
    ListNode *pre;
    ListNode *index = NULL;
    while(p != NULL) {
        if(p->val < x) {
            pre->next = p->next;
            p->next = index->next;
            index->next = p;
            p = pre->next;
            index = index->next;
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
