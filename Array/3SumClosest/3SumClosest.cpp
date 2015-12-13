
//3Sum Closest

#include <iostream>
#include <vector>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	int length = nums.size();
	int result = 0;
	int gap = INT_MAX;
	if(length <= 0)
		return result;
	sort(nums.begin(), nums.end());
	for(int i = 0; i < length; i++) {
		int j = i+1;
		int k = length - 1;
		while(j < k) {
			int tmp = nums[i] + nums[j] + nums[k];

			if(tmp == target) {
				gap = 0;
				result = tmp;
				break;
			} else if(tmp < target) {
				j++;
				if(abs(tmp - target) <= gap) {
					gap = abs(tmp - target);
					result = tmp;
				}
			} else {
				k--;
				if(abs(tmp - target) <= gap) {
					gap = abs(tmp - target);
					result = tmp;
				}
			}
		}
	}
	return result;
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);

	// nums.push_back(-1);
	// nums.push_back(2);
	// nums.push_back(1);
	// nums.push_back(-4);
	int target = -100;
	int result = threeSumClosest(nums, target);
	cout<<result<<endl;
	return 0;
}