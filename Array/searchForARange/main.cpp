
//Search for a Range

#include <iostream>
#include <vector>

using namespace std;

//寻找上边界
int searchUpperBound(vector<int> &nums, int target)
{
    int length = nums.size();
    int low = 0;
    int high = length - 1;
    int mid;

    if(low > high || target > nums[high] || target < nums[low])
        return -1;
    while(low < high) {
        mid = low + (high - low) / 2;
        if(nums[mid] > target)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

//寻找下边界
int searchLowerBound(vector<int> &nums, int target)
{
    int length = nums.size();
    int low = 0;
    int high = length;
    int mid;
    if(low >= high || target <= nums[low])
        return -1;
    while(low < high) {
        mid = low + (high - low) / 2;
        if(target <= nums[mid])
            high = mid;
        else
            low = low + 1;
    }
    return low - 1;
}

//查找重复出现元素中的第一个
//正常情况下，进行二分查找，通常分为三种情况，大于、等于、小于，然后根据不同的情况进行判断
//对于查找第一个出现的元素，也是分为三种情况，一、target等于且是第一个元素，二、target大于mid
//三、target小于mid或者是target等于mid但不是第一个出现的值
//具体可以参考这篇文章http://www.geeksforgeeks.org/count-number-of-occurrences-in-a-sorted-array/
int searchFirst(vector<int> &nums, int target)
{
    int length = nums.size();
    int low = 0;
    int high = length - 1;
    int mid;

    while(low <= high) {
        mid = low + (high - low) / 2;
        if((target > nums[mid - 1] || mid == 0) && target == nums[mid])
            return mid;
        else if(target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int searchLast(vector<int> &nums, int target)
{
    int length = nums.size();
    int low = 0;
    int high = length - 1;
    int mid;

    while(low <= high) {
        mid = low + (high - low) / 2;
        if((target < nums[mid + 1] || mid == length - 1) && nums[mid] == target)
            return mid;
        else if(target < nums[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> result;
    int first = searchFirst(nums, target);
    int last = searchLast(nums, target);
    result.push_back(first);
    result.push_back(last);
    return result;
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
    for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        cout<<*iter<<" ";
    cout<<endl;
}


int main()
{
    int arr[] = {2, 3, 5, 7, 7,11, 13, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums;
    nums = arrayToVector(arr, n);
    int target = 7;
    vector<int> result = searchRange(nums, target);
    cout<<"The Result is: ";
    printVector(result);
    return 0;
}
