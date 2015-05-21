
//Rotate Array

#include <iostream>
#include <vector>

using namespace std;

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int reverse(vector<int> &nums, int l, int r)
{
    if(l > r)
        return 0;
    for(int i = l, j = r; i <= j; i++, j--) {
        Swap(&nums[i], &nums[j]);
    }
    return 1;
}

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if(n == 0)
        return;
    k = k % n;
    int midPos = n-k;
    reverse(nums, 0, midPos-1);
    reverse(nums, midPos, n-1);
    reverse(nums, 0, n-1);
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void printVector(vector<int> &nums)
{
    int n = nums.size();
    if(n == 0)
        return;
    for(int i = 0; i < n; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int main()
{
    vector<int> nums;
    int k = 3;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    cout<<"Before Reverse: ";
    printVector(nums);
    rotate(nums, k);
    cout<<"After Reverse: ";
    printVector(nums);
    return 0;
}
