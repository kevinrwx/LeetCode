
//single number II

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;



int singleNumber(vector<int>& nums)
{
    const int W = sizeof(int) * 8;
    int count[W];
    memset(count, 0, sizeof(int) * W);

    for(vector<int>::size_type i = 0; i < nums.size(); i++) {
        for(int j = 0; j < W; j++) {
            count[j] += (nums[i] >> j) & 1;
            count[j] %= 3;
        }
    }
    int result = 0;
    for(int k = 0; k < W; k++) {
        result += (count[k] << k);
    }
    return result;
}

int main()
{
//    int A[] = {1,1,1,2,2,2,3,3,3,4,4,4,5};
//    int n = sizeof(A)/sizeof(A[0]);
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    cout<<"The number is: "<<singleNumber(nums)<<endl;
    return 0;
}
