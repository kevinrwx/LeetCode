
//Palindrome Linked List

#include <iostream>
// #include <string>

using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
   if(head == NULL || head->next == NULL)
       return head;
   ListNode* dummy = new ListNode(-1);
   ListNode* pNode = head;
   while(pNode != NULL) {
       ListNode* tmp = dummy->next;
       dummy->next = pNode;
       pNode = pNode->next;
       dummy->next->next = tmp;
   }
   return dummy->next;
}

bool isPalindrome(ListNode* head) {
   if(head == NULL)
       return true;
   string orderSequence;
   string reverseSequence;
   ListNode* pNode = head;
   while(pNode != NULL) {
       orderSequence.append(to_string(pNode->val));
       pNode = pNode->next;
   }
   pNode = reverseList(head);
   while(pNode != NULL) {
       reverseSequence.append(to_string(pNode->val));
       pNode = pNode->next;
   }
   return orderSequence == reverseSequence;
}

int main() {
   ListNode* head = new ListNode(1);
   head->next = new ListNode(2);
   head->next->next = new ListNode(2);
   head->next->next->next = new ListNode(1);
   if(isPalindrome(head))
       cout<<"is Palindrome"<<endl;
   else
   	   cout<<"not Palindrome"<<endl;
   return 0;
}
