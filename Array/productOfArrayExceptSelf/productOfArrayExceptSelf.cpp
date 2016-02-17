
//Product of Array Except Self

#include <iostream>
#include <vector>

using namespace std;

//这种方法可以通过，但是这种方法并不能满足题目不用除法的要求
// vector<int> productExceptSelf(vector<int>& nums) {
// 	int length = nums.size();
// 	vector<int> result(length, 0);
// 	if(length <= 0)
// 		return result;
// 	int product = 1;
// 	int count = 0;
// 	for(int i = 0; i < length; i++) {
// 		product *= (nums[i] != 0) ? nums[i] : 1;
// 		if(nums[i] == 0)
// 			count++;
// 	}
// 	if(count == 1) {
// 		for(int i = 0; i < length; i++) {
// 			if(nums[i] == 0)
// 				result[i] = product;
// 		}
// 	} else if(count == 0) {
// 		for(int i = 0; i < length; i++) {
// 			result[i] = product / nums[i];
// 		}
// 	}
// 	return result;
// }

//维持两个数组，left[]和right[]，left[i]和right[i]分别记录第i个元素左边元素相乘的积和右边元素相乘的积，那么
//结果result[i]就是left[i]*right[i]，但是由于题目要求额外的空间为o(1)，所以我们要利用返回的结果数组，先存right
//数组，再从左边计算left，同时计算结果值
// vector<int> productExceptSelf(vector<int>& nums) {
// 	int length = nums.size();
// 	vector<int> result(length, 0);
// 	if(length <= 0)
// 		return result;
// 	vector<int> left(length, 1);
// 	vector<int> right(length, 1);
// 	for(int i = 1; i < length; i++) {
// 		left[i] = nums[i-1] * left[i-1];
// 	}
// 	for(int i = length-2; i >= 0; i--) {
// 		right[i] = nums[i+1] * right[i+1];
// 	}
// 	for(int i = 0; i < length; i++) {
// 		result[i] = left[i] * right[i];
// 	}
// 	return result;
// }

//这段代码是最后的结果，充分利用了最后的结果数组result，而没有额外使用新的空间
vector<int> productExceptSelf(vector<int>& nums) {
	int length = nums.size();
	vector<int> result(length, 0);
	if(length <= 0)
		return result;
	result[length - 1] = 1;
	for(int i = length-2; i >= 0; i--) {
		result[i] = nums[i+1] * result[i+1];
	}
	int leftProduct = 1;
	for(int i = 0; i < length; i++) {
		result[i] = result[i] * leftProduct;
		leftProduct *= nums[i];
	}
	return result;
}

vector<int> arr2vec(int arr[], int n) {
    vector<int> result;
    for(int i = 0; i < n; i++)
        result.push_back(arr[i]);
    return result;
}

void printVec(vector<int>& nums) {
    int length = nums.size();
    if(length <= 0)
        cout<<"empty vector"<<endl;
    for(int i = 0; i < length; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums = arr2vec(arr, n);
    vector<int> result = productExceptSelf(nums);
    printVec(result);
    return 0;
}