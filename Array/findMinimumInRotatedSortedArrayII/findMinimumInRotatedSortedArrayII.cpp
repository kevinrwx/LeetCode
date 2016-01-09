
//Find Minimum in Rotated Sorted Array II

#include <iostream>
#include <vector>

using namespace std;

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

//还有一种使用二分搜索的方法，这种方法我还没有想出来，具体的情况还需要再考虑
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