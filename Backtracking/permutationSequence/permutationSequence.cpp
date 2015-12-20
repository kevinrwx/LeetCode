
//Permutation Sequence

//这题的代码主要参考下面代码的思路
#include <iostream>
#include <vector>

using namespace std;

int getFactorial(int n) {
	if(n == 0)
		return 1;
	else
		return n*getFactorial(n-1);
}

void backtrack(string* result, string nums, int k) {
	if(nums.length() == 1) {
		(*result).push_back(nums[0]);
	}
	else {
		int length = nums.length();
		int dividend = getFactorial(length - 1);
		int index = k / dividend;
		k %= dividend;
		(*result).push_back(nums[index]);
		nums.erase(nums.begin() + index);
		backtrack(result, nums, k);
	}
}

string getPermutation(int n, int k) {
	string result;
	string nums;
	char ch[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	for(int i = 0; i < n; i++)
		nums.push_back(ch[i]);
	backtrack(&result, nums, k-1);
	return result;

}

int main() {
	int n = 3, k = 4;
	string result = getPermutation(n, k);
	cout<<result<<endl;
	return 0;
}



//对于递归的思路是，每次先做k / (n-1)! = index.....k，结果是index，余数是k，则每次要把nums[index]位置上的
//数字取出来，然后把剩下的数字按照从小到大的顺序排好，接着进行下一步的递归，直到nums数组最后只剩一个元素，则递归
//结束，返回最后一个值
// #include <iostream>
// #include <vector>

// using namespace std;

// int getFactorial(int n) {
// 	if(n == 0)
// 		return 1;
// 	else
// 		return n*getFactorial(n-1);
// }

// void backtrack(vector<int>& result, vector<int>& nums, int k) {
// 	if(nums.size() == 1)
// 		result.push_back(nums[0]);
// 	else {
// 		int length = nums.size();
// 		int dividend = getFactorial(length - 1);
// 		int index = k / dividend;
// 		k %= dividend;
// 		result.push_back(nums[index]);
// 		nums.erase(nums.begin() + index);
// 		backtrack(result, nums, k);
// 	}
// }

// vector<int> getPermutaion(int n, int k) {
// 	vector<int> result;
// 	vector<int> nums(n, 0);
// 	for(int i = 0; i < n; i++)
// 		nums[i] = i+1;
// 	backtrack(result, nums, k-1);
// 	return result;
// }

// int main() {
// 	int n = 3, k = 4;
// 	vector<int> result = getPermutaion(n, k);
// 	for(int i = 0; i < result.size(); i++)
// 		cout<<result[i]<<" ";
// 	cout<<endl;
// 	return 0;
// }











