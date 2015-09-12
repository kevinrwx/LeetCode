
//House Robber II

#include <iostream>
#include <vector>

using namespace std;

//由于第一个和最后一个是连接在一起的，所以只需要计算出第一个到倒数第二个和第二个到倒数最后一个的最大数值，然后取最值就可以了
int rob(vector<int> &nums) {
	if(nums.size() == 0)
		return 0;
	if(nums.size() == 1)
		return nums[0];
	vector<int> dp(nums.size());
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for(int i = 1; i < nums.size() - 1; i++) {
		dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
	}
	int result1 = dp[nums.size() - 2];
	dp[1] = nums[1];
	dp[2] = max(nums[1], nums[2]);
	for(int i = 3; i < nums.size(); i++) {
		dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
	}
	int result2 = dp[nums.size() - 1];
	return result1 >= result2 ? result1 : result2;
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	int result = rob(nums);
	cout<<"result: "<<result<<endl;
	return 0;
}