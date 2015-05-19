
//Convert Sorted List to Binary Search Tree

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(int arr[], int Start, int End)
{
    if(Start > End)
        return NULL;
    int Mid = Start + (End - Start) / 2;
    TreeNode* root = new TreeNode(arr[Mid]);
    root->left = sortedArrayToBST(arr, Start, Mid-1);
    root->right = sortedArrayToBST(arr, Mid+1, End);
    return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
    if(head == NULL)
        return NULL;
    ListNode* p = head;
    int counts = 0;
    int n = 0;
    while(p != NULL) {
        counts++;
        p = p->next;
    }
    int arr[counts];
    p = head;
    while(p != NULL) {
        arr[n++] = p->val;
    }
    TreeNode* root = sortedArrayToBST(arr, 0, counts-1);
    return root;
}

ListNode* arrayToList(int arr[], int n)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    for(int i = 0; i < n; i++) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    return dummy->next;
}

void preOrder(TreeNode* root)
{
    if(root != NULL) {
        preOrder(root->left);
        cout<<root->val<<" ";
        preOrder(root->right);
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
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

}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"Before sortedArrayToBST: ";
    printArray(A, n);
    ListNode* head = arrayToList(A, n);
    cout<<"arrayToList: ";
    printList(head);
    cout<<endl;
    cout<<"Before sortedListToBST: ";
    TreeNode* root = sortedListToBST(head);
    preOrder(root);
    return 0;
}
