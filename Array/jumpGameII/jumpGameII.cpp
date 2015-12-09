
//Jump Game II

#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
	int length = nums.size();
	int res = 0;
	if(length <= 0) {
		return res;
	}
	int maxLocal = 0;
	int maxLocalIndex = 0;
	for(int i = 0; i < length; i++) {
		if(maxLocal - i + maxLocalIndex >= 0) {
			if(nums[i] >= maxLocal && (maxLocal < length - 1 - maxLocalIndex)) {
				maxLocal = nums[i];
				maxLocalIndex = i;
				res++;
			}
		}
	}
	if(maxLocal == nums[length - 1])
		res--;
	return res;
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	// nums.push_back(4);
	int result = jump(nums);
	cout<<"jumps: "<<result<<endl;
	return 0;
}