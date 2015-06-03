
//Contains Duplicate

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    int length = nums.size();
    if(length == 0)
        return false;
    unordered_map<int, int> mapping;
    for(int i = 0; i < length; i++) {
        if(mapping.find(nums[i]) != mapping.end()) {
            return true;
        }
        else {
            mapping[nums[i]] = 1;
        }
    }
    return false;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    //nums.push_back(1);
    bool result = containsDuplicate(nums);
    if(result)
        cout<<"contains duplicate"<<endl;
    else
        cout<<"contains no duplicate"<<endl;
    return 0;
}
