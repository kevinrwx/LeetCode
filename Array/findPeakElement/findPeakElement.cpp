
//Find Peak Element

#include <iostream>
#include <vector>

using namespace std;

//这道题的思路比较简单，直接进行遍历就可以了，时间复杂度为o(n)，不过这道题目的标签有Binary Search，也许可以
//通过Binary Search来降低时间复杂度
int findPeakElement(vector<int>& nums) {
	if(nums.empty())
		return -1;
	int length = nums.size();
	int i = 0;
	while(i < length - 1) {
		if(nums[i] < nums[i+1])
			i++;
		else
			break;
	}
	return i;
}

vector<int> arr2Vec(int arr[], int n) {
	vector<int> result;
	for(int i = 0; i < n; i++)
		result.push_back(arr[i]);
	return result;
}

int main() {
	int arr[] = {1, 2, 3, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> nums = arr2Vec(arr, n);
	int index = findPeakElement(nums);
	cout<<index<<endl;
	return 0;
}