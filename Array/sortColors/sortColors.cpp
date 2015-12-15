
//Sort Colors

#include <iostream>
#include <vector>

using namespace std;

//一轮的基数排序，比较简单
void sortColors(vector<int>& nums) {
	int length = nums.size();
	vector<int> tmp(length, 0);
	vector<int> count(3, 0);
	for(int i = 0; i < length; i++) {
		count[nums[i]]++;
	}
	for(int i = 1; i < count.size(); i++)
		count[i] += count[i-1];
	for(int i = length - 1; i >= 0; i--) {
		tmp[count[nums[i]] - 1] = nums[i];
		count[nums[i]]--;
	}
	for(int i = 0; i < length; i++)
		nums[i] = tmp[i];
}

void printVector(vector<int>& nums) {
	int length = nums.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++)
		cout<<nums[i]<<" ";
	cout<<endl;
}

int main() {
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	printVector(nums);
	sortColors(nums);
	printVector(nums);
	return 0;
}