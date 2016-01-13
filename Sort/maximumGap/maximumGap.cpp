
//Maximum Gap

#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& nums, int left, int right) {
	if(left < right) {
		int i = left, j = right, tmp = nums[left];
		while(i < j) {
			while(i < j && nums[j] >= tmp)
				j--;
			if(i < j)
				nums[i++] = nums[j];
			while(i < j && nums[i] < tmp)
				i++;
			if(i < j)
				nums[j--] = nums[i];
		}
		nums[i] = tmp;
		quickSort(nums, left, i-1);
		quickSort(nums, i+1, right);
	}
}

int maximumGap(vector<int>& nums) {
	if(nums.size() < 2)
		return 0;
	int length = nums.size();
	int gap = 0;
	quickSort(nums, 0, length - 1);
	for(int i = 1; i < length; i++) {
		gap = max(gap, (nums[i] - nums[i - 1]));
	}
	return gap;
}

int main() {
	//
}