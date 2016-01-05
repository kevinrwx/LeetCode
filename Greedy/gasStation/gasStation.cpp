
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

//求普通数组最大连续子序列和的代码
// int maxSumSubarray(vector<int>& nums) {
//     int length = nums.size();
//     int ans = 0;
//     if(length <= 0)
//         return ans;
//     int tmp = 0;
//     for(int i = 0; i < length; i++) {
//         tmp = max(nums[i], tmp + nums[i]);
//         ans = max(ans, tmp);
//     }
//     return ans;
// }

//这道题目参考了网上的代码，复杂度是o(n)，思路是如果从i开始计算balance，即balance[i]+balance[i+1]+...+balance[p] < 0
//而balance[i]+..+balance[p-1] >= 0，则从i到p的所有点都不能成为初始出发点，只能从p+1开始出发
//如果从p+1开始出发后，一直到了n-1，balance的和都大于0，而且total的和也大于0，那么就不用再计算从0到p的和了，因为所有的balance和大于0
//这就保证了最后该车能从p+1开回p
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if(gas.empty() || cost.empty() || gas.size() != cost.size())
        return -1;
    int length = gas.size();
    int total = 0;
    int sum = 0;
    int index = 0;
    vector<int> balance(length, 0);
    for(int i = 0; i < length; i++)
        balance[i] = gas[i] - cost[i];
    for(int i = 0; i < length; i++) {
        total += balance[i];
        if(sum < 0) {
            sum = balance[i];
            index = i;
        } else {
            sum += balance[i];
        }
    }
    return total < 0 ? -1 : index;
}

int main()
{
    vector<int> gas;
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(4);
    gas.push_back(5);
    gas.push_back(6);

    vector<int> cost;
    cost.push_back(1);
    cost.push_back(2);
    cost.push_back(3);
    cost.push_back(4);
    cost.push_back(5);

    int result = canCompleteCircuit(gas, cost);
    cout<<"result: "<<result<<endl;
    return 0;

}
