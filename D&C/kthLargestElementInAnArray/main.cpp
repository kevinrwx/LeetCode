
//Kth Largest Element in an Array

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

//method I
//This is the simplest way to solve the problem
int findKthLargest(vector<int> &nums, int k)
{
    int length = nums.size();
    int result;
    if(length == 0)
        return 0;
    sort(nums.begin(), nums.end());
    result = nums[length - k];
    return result;
}

//method II
//using max heap
void printVector(vector<int> &nums);
int Left(int i)
{
    return 2 * i + 1;
}

int Right(int i)
{
    return 2 * i + 2;
}

void Swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void maxHeapify(vector<int> &nums, int i)
{
    int left = Left(i);
    int right = Right(i);
    int maximum = i;
    int length = nums.size();

    if(left < length && nums[maximum] < nums[left])
        maximum = left;
    if(right < length && nums[maximum] < nums[right])
        maximum = right;
    if(maximum != i) {
        Swap(&nums[maximum], &nums[i]);
        maxHeapify(nums, maximum);
    }
}

void buildHeap(vector<int> &nums)
{
    int length = nums.size();
    for(int i = length / 2; i >= 0; i--)
        maxHeapify(nums, i);
}

int extractMax(vector<int> &nums)
{
    int length = nums.size();
    int result;
    vector<int>::iterator it;
    if(length == 0)
        return INT_MAX;
    result = nums[0];
    Swap(&nums[0], &nums[length - 1]);
    it = nums.end() - 1;
    nums.erase(it);
    maxHeapify(nums, 0);
    return result;
}

int findKthLargest(vector<int> &nums, int k)
{
    int length = nums.size();
    int result;
    vector<int>::iterator it;
    if(length == 0)
        return 0;
    buildHeap(nums);
    for(int i = k-1; i > 0; i--) {
        extractMax(nums);
    }
    result = nums[0];
    return result;
}


void printVector(vector<int> &nums)
{
    int length = nums.size();
    if(length == 0)
        cout<<"Empty Vector"<<endl;
    vector<int>::iterator iter;
    for(iter = nums.begin(); iter != nums.end(); iter++)
        cout<<*iter<<" ";
    cout<<endl;
}

vector<int> arrTovector(int arr[], int n)
{
    vector<int> nums;
    for(int i = 0; i < n; i++)
        nums.push_back(arr[i]);
    return nums;
}

int main()
{
    vector<int> nums;
    int arr[] = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    int n = sizeof(arr)/ sizeof(arr[0]);
    nums = arrTovector(arr, n);
    printVector(nums);
    int k = 20;
    int result = findKthLargest(nums, k);
    cout<<"The Result Is: "<<result<<endl;
    return 0;
}

