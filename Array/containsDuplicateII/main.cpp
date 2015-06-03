
//Contains Duplicate II

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int length = nums.size();
    if(length == 0)
        return false;
    unordered_map<int, int> mapping;
    int tmp = 0;
    for(int i = 0; i < length; i++) {
        if(mapping.find(nums[i]) != mapping.end()) {
            tmp = i > mapping[nums[i]] ? (i - mapping[nums[i]]) : (mapping[nums[i]] - i);
            if(tmp <= k)
                return true;
            else {
                mapping[nums[i]] = i;
            }
        }
        else {
            mapping[nums[i]] = i;
        }
    }
    return false;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
//    nums.push_back(1);
    int k = 1;
    bool result = containsNearbyDuplicate(nums, k);
    if(result)
        cout<<"contains nearby duplicate: "<<endl;
    else
        cout<<"contains no nearby duplicate"<<endl;
    return 0;
}
