
//Find Minimum in Rotated Sorted Array

#include <iostream>
#include <vector>

using namespace std;

// int findMin(vector<int>& nums) {
// 	if(nums.empty())
// 		return -1;
// 	int left = 0;
// 	int right = nums.size()-1;
// 	int mid;
// 	while(left + 1 != right) {
// 		mid = left + (right - left) / 2;
// 		if(nums[mid] > nums[left]) {
// 			left = mid + 1;
// 		}
// 		else if(nums[mid] < nums[right]) {
// 			right = mid - 1;
// 		}
// 	}
// 	return min(nums[left], nums[right]);
// }

//这种方法特别容易想到，那就是挨个遍历，最后总会找到最小的那个元素，所以这种方法的复杂度是o(n)
// int findMin(vector<int>& nums) {
// 	if(nums.empty())
// 		return -1;
// 	int tmp = nums[0];
// 	int length = nums.size();
// 	for(int i = 0; i < length; i++) {
// 	    if(nums[i] <= tmp)
// 	        tmp = nums[i];
// 	}
// 	return tmp;
// }

//这种解法使用了二分搜索的思想，但是并不是那么的完美，刚开始会将搜索范围减半，但是后来会降成了挨个遍历
//所以这种方法的复杂度介于o(n)和o(logn)之间
// int findMin(vector<int>& nums) {
// 	int length = nums.size() - 1;
// 	int left = 0;
// 	int right = length;
// 	int mid;
// 	while(left <= right) {
// 		mid = left + (right - left) / 2;
// 		if(nums[mid] > nums[length])
// 			left = mid + 1;
// 		else
// 			right = mid - 1;
// 	}
// 	return nums[left];
// }

int findMin(vector<int>& nums) {
	int left = 0;
	int right = nums.size() - 1;
	int mid;
	if(nums[left] < nums[right])
		return nums[left];
	while(left + 1 < right) {
		mid = left + (right - left) / 2;
		if(nums[mid] > nums[right])
			left = mid;
		else
			right = mid;
	}
	return min(nums[left], nums[right]);
}

vector<int> arr2Vec(int nums[], int n) {
	vector<int> result;
	for(int i = 0; i < n; i++)
		result.push_back(nums[i]);
	return result;
}



int main() {
	int arr[] = {6, 7, 8, 1, 1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> nums = arr2Vec(arr, n);
	int result = findMin(nums);
	cout<<result<<endl;
	return 0;
}