
//Search in Rotated Sorted Array II

#include <iostream>
#include <vector>

using namespace std;

//int search(vector<int> &nums, int target)
//{
//    int length = nums.size();
//    if(length == 0)
//        return -1;
//    int low = 0;
//    int high = length - 1;
//    int mid;
//
//    while(low <= high) {
//        mid = low + (high - low) / 2;
//        if(target == nums[mid])
//            return mid;
//        else if(target < nums[mid]) {
//            if(nums[mid] < nums[high])
//                high = mid - 1;
//            else
//                if(target <= nums[low])
//                    low = mid + 1;
//                else
//                    high = mid - 1;
//        }
//        else {
//            if(nums[mid] > nums[low])
//                low = mid + 1;
//            else
//                if(target <= nums[high])
//                    low = mid + 1;
//                else
//                    high = mid - 1;
//        }
//    }
//    return -1;
//}

//int search(vector<int> &nums, int target)
//{
//    int length = nums.size();
//    if(length == 0)
//        return -1;
//    int low = 0;
//    int high = length;
//    int mid;
//
//    while(low < high) {
//        mid = low + (high - low) / 2;
//        if(target == nums[mid])
//            return mid;
//        else if(target < nums[mid]) {
//            if(nums[mid] < nums[high])
//                high = mid;
//            else
//                if(target >= nums[low])
//                    high = mid;
//                else
//                    low = mid + 1;
//        }
//        else {
//            if(nums[mid] > nums[low])
//                low = mid + 1;
//            else
//                if(target <= nums[high])
//                    low = mid + 1;
//                else
//                    high = mid;
//        }
//    }
//    return -1;
//}

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
//    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int arr[] = {3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> nums;
    nums = arrayToVector(arr, n);
    int target = 3;
    int result = search(nums, target);
    cout<<"The result is: "<<result<<endl;
    return 0;
}
