
//next permutation

#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//这题不是独自想出来的
//具体思路是：先从后到前进行遍历，找到第一个从左到右的升序的相邻元素，分别记为left、right(left < right)；然
//后再从右向左遍历，找到第一个比left小的元素j；接着根据i是否大于0来判断是否交换nums[left]和nums[j]；最后将
//从right到最后的元素进行翻转
void nextPermutation(vector<int>& nums) {
	int length = nums.size();
	if(length < 2)
		return ;
	int i, j;
	for(i = length - 2; i >= 0; i--)
		if(nums[i] < nums[i+1])
			break;
	for(j = length - 1; j > i; j--)
		if(nums[j] > nums[i])
			break;
	if(i >= 0)
		swap(&nums[i], &nums[j]);
	reverse(nums.begin()+i+1, nums.end());
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
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	printVector(nums);
	nextPermutation(nums);
	printVector(nums);
	return 0;
}