
//Search for a Range

#include <iostream>
#include <vector>

using namespace std;

//Ѱ���ϱ߽�
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

//Ѱ���±߽�
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

//�����ظ�����Ԫ���еĵ�һ��
//��������£����ж��ֲ��ң�ͨ����Ϊ������������ڡ����ڡ�С�ڣ�Ȼ����ݲ�ͬ����������ж�
//���ڲ��ҵ�һ�����ֵ�Ԫ�أ�Ҳ�Ƿ�Ϊ���������һ��target�������ǵ�һ��Ԫ�أ�����target����mid
//����targetС��mid������target����mid�����ǵ�һ�����ֵ�ֵ
//������Բο���ƪ����http://www.geeksforgeeks.org/count-number-of-occurrences-in-a-sorted-array/
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
