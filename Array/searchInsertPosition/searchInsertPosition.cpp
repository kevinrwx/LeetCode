
//Search Insert Position

#include <iostream>
#include <vector>

using namespace std;


//编程珠玑中的二分查找的实现，如果存在多个相同的target元素时，返回第一个元素
int binarySearch(vector<int>& nums, int target) {
	int length = nums.size();
	int left = -1;
	int right = length;
	int mid;
	while(left + 1 != right) {
		mid = left + (right - left) / 2;
		if(nums[mid] < target)
			left = mid;
		else
			right = mid;
	}
	// if(right >= length || nums[right] != target) {
	// 	right = -1;
	// }
	return right;
}




int searchInsert(vector<int>& nums, int target) {
	int length = nums.size();
	if(length <= 0)
		return 0;
	int left = -1;
	int right = length;
	int mid;
	while(left + 1 != right) {
		mid = left + (right - left) / 2;
		if(nums[mid] >= target) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return right;
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	int target = 7;
	// int index = binarySearch(nums, target);
	int index = searchInsert(nums, target);
	cout<<"index: "<<index<<endl;
	return 0;
}