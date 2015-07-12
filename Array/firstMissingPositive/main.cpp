
//First Missing Positive

#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

//int firstMissingPositive(vector<int>& nums)
//{
//    int length = nums.size();
//    if(length == 0)
//        return 0;
//    bool* tmp = new bool[length];
//    memset(tmp, false, length*sizeof(bool));
//    for(int i = 0; i < length; i++) {
//        if(nums[i] >= 0)
//            tmp[nums[i]] = true;
//    }
//    int j;
//    for(j = 0; j < length; j++) {
//        if(tmp[j] == false)
//            return j;
//    }
//    if(j == length)
//        return j;
//    delete[] tmp;
//}

void Swap(int *x, int *y) {
    int tmp = *y;
    *y = *x;
    *x = tmp;
}

//int firstMissingPositive(vector<int> &nums)
//{
//    int length = nums.size();
//    if(length == 0)
//        return 0;
//    int counts = 0;
//    int index = 0;
//    int tmp = 0;
//    while(counts < length) {
//        if(index != nums[index]) {
//            tmp = nums[index];
//            if(tmp >= 0 && tmp < length) {
//                Swap(&nums[index], &nums[tmp]);
//                index = nums[index];
//            }
//            else {
//                index = ;
//            }
//        }
//        counts++;
//    }
//    int i;
//    for(i = 0; i < length; i++) {
//        if(nums[i] >= 0 && nums[i] != i)
//            return i;
//    }
//    return i;
//}

int firstMissingPositive(vector<int> &nums)
{
    int length = nums.size();
    if(length == 0)
        return 1;
    int *tmp = new int[length + 1];
    memset(tmp, 0, (length + 1)*sizeof(int));
    for(int i = 1; i <= length; i++) {
        if(nums[i - 1] >= 1 && nums[i - 1] <= length) {
            tmp[nums[i - 1]] = nums[i - 1];
        }
    }
    int j;
    for(j = 1; j <= length; j++) {
        if(tmp[j] != j)
            return j;
    }
    delete[] tmp;
    return j;
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(1);
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(0);
    int result = firstMissingPositive(nums);
    cout<<"The result is: "<<result<<endl;
    return 0;
}
