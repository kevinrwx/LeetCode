
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
    int *tmp = new int[length];
    memset(tmp, 0, length*sizeof(int));
    for(int i = 0; i < length; i++) {
        if(nums[i] >= 0 && nums[i] < length) {
            tmp[nums[i]] = nums[i];
        }
    }
    int j;
    for(j = 0; j < length; j++) {
        if(tmp[j] != j)
            return j;
    }
    return j;
    delete[] tmp;
}

int main()
{
    vector<int> nums;
//    nums.push_back(3);
//    nums.push_back(4);
//    nums.push_back(-1);
//    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    int result = firstMissingPositive(nums);
    cout<<"The result is: "<<result<<endl;
    return 0;
}
