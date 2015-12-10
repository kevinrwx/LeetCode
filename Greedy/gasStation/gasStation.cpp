
//Gas Station

#include <iostream>
#include <vector>

using namespace std;

//先求出balance的向量，接下来这个问题就变成了求循环数组的最大连续子序列和问题
//最大连续子序列和可以用DP来解决，递推公式为：sum[i] = max(sum[i]+a[i], a[i]);
void printVector(vector<int>& nums) {
	int length = nums.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++)
		cout<<nums[i]<<" ";
	cout<<endl;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int length = gas.size();
    if(length == 0)
        return -1;
    vector<int> balance(length, 0);
    for(int i = 0; i < length; i++) {
        balance[i] = gas[i] - cost[i];
    }
    vector<int> result(length, 0);
    vector<int> tmp(length, 0);
    for(int i = 0; i < 2*length - 1; i++) {
    	tmp[i] = max(tmp[i]+balance[i], balance[i]);
    	result[i] = max(result[i], tmp[i]);
    }
    int ans = 0;
    for(int i = 0; i < length; i++) {
    	ans = max(ans, result[i]);
    }
    return ans;
}

int maxSumSubarray(vector<int>& nums) {
	int length = nums.size();
	int ans = 0;
	if(length <= 0)
		return ans;
	int tmp = 0;
	for(int i = 0; i < length; i++) {
		tmp = max(nums[i], tmp + nums[i]);
		ans = max(ans, tmp);
	}
	return ans;
}

int main()
{
    // vector<int> gas;
    // gas.push_back(2);
    // gas.push_back(3);
    // gas.push_back(4);
    // gas.push_back(5);
    // gas.push_back(6);

    // vector<int> cost;
    // cost.push_back(1);
    // cost.push_back(2);
    // cost.push_back(3);
    // cost.push_back(4);
    // cost.push_back(5);

    // int result = canCompleteCircuit(gas, cost);
    // cout<<"result: "<<result<<endl;


    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    int result = maxSumSubarray(nums);
    cout<<result<<endl;
    return 0;

}
