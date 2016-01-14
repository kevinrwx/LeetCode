
//Find Peak Element

#include <iostream>
#include <vector>

using namespace std;

//这道题的思路比较简单，直接进行遍历就可以了，时间复杂度为o(n)，不过这道题目的标签有Binary Search，也许可以
//通过Binary Search来降低时间复杂度
// int findPeakElement(vector<int>& nums) {
// 	if(nums.empty())
// 		return -1;
// 	int length = nums.size();
// 	int i = 0;
// 	while(i < length - 1) {
// 		if(nums[i] < nums[i+1])
// 			i++;
// 		else
// 			break;
// 	}
// 	return i;
// }

//采用二分查找思想的答案，这是从网上找到的答案，感觉不是特别容易理解，而且也不太容易想到这种解决方法
int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low < high) {
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[mid+1])
                high = mid;
            else
                low = mid+1;
        }
        return low;
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