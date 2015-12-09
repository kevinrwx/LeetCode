
//Jump Game

#include <iostream>
#include <vector>

using namespace std;

//从第一个位置开始起跳，可跳跃步数为nums[0]，然后每次跳跃一步，可跳跃步数减一
//如果新位置的步数比剩余可跳跃步数大，则更新可跳跃步数为新位置的步数
bool canJump(vector<int>& nums) {
	int length = nums.size();
	if(length == 0)
		return true;
	int maxLocal = nums[0];
	for(int i = 1; i < length; i++) {
		maxLocal--;
		if(maxLocal < 0) {
			return false;
		}
		if(maxLocal < nums[i]) {
			maxLocal = nums[i];
		}
	}
	return true;
}

//采用动态规划的方法，设状态f[i]表示从第0层出发，走到nums[i]时剩余的最大步数
//则状态转移方程为：f[i] = max(f[i-1], nums[i-1]) - 1
bool canJump(vector<int>& nums) {
	int length = nums.size();
	if(length == 0) {
		return true;
	}
	int fi = 0;
	for(int i = 1; i < length; i++) {
		fi = max(fi, nums[i-1]) - 1;
		if(fi < 0) {
			return false;
		}
	}
	return fi >= 0;
}



int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	bool result = canJump(nums);
	if(result)
		cout<<"can jump";
	else
		cout<<"can't jump";
	return 0;
}