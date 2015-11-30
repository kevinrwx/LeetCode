
//remove element

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	int length = nums.size();
	if(length <= 0)
		return 0;
	int index = 0;
	for(int i = 0; i < length; i++) {
		if(nums[i] != val) {
			nums[index++] = nums[i];
		}
	}
	return index;
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(3);
	int val = 3;
	int result = removeElement(nums, val);
	cout<<result<<endl;
	return 0;
}