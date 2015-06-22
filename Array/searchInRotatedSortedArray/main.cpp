



//Search in Rotated Sorted Array


#include <iostream>


using namespace std;

int pivotIndex(int A[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        if(A[i] <= A[i+1])
            continue;
        else
            return i;
    }
    return -1;
}

int binarySearch(int A[], int left, int right, int target)
{
    int low = left;
    int high = right;
    int mid;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        if(target == A[mid])
            return mid;
        else if(target < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

//method I
int search(int A[], int n, int target)
{
    //
    int pivot;
    int index;
    if(n == 0)
        return -1;
    else
    {
        //
        pivot = pivotIndex(A, n);
        if(pivot == -1)
        {
            index = binarySearch(A, 0, n-1, target);
            return index;
        }
        else
        {
            index = binarySearch(A, 0, pivot, target);
            if(index == -1)
            {
                index = binarySearch(A, pivot+1, n-1, target);
                return index;
            }
            else
                return index;
        }
    }
}

//method II
int search(vector<int> &nums, int target)
{
    int length = nums.size();
    if(length == 0)
        return -1;
    int low = 0;
    int high = length;
    int mid;

    while(low < high) {
        mid = low + (high - low) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[low] <= nums[mid]) {
            if(target < nums[mid] && target >= nums[low])
                high = mid;
            else
                low = mid + 1;
        }
        else {
            if(target > nums[mid] && target <= nums[high - 1])
                low = mid + 1;
            else
                high = mid;
        }
    }
    return -1;
}


vector<int> arrayToVector(int arr[], int n)
{
    vector<int> nums;
    for(int i = 0; i < n; i++)
        nums.push_back(arr[i]);
    return nums;
}

void printVector(vector<int> &nums)
{
    int length = nums.size();
    if(length == 0)
        cout<<"Empty Vector"<<endl;
    for(int i = 0; i < length; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}


int main()
{
    //
//    int A[] = {0, 1, 2, 4, 5, 6, 7};
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    int N = sizeof(A) / sizeof(A[0]);
    int index;
    int target = 8;
//    index = binarySearch(A, 0, N-1, 8);
    index = search(A,N,target);
    cout<<index;
    return 0;
}




