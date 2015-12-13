
//3Sum

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<vector<int> >&nums) {
	int length = nums.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++) {
		for(int j = 0; j < nums[i].size(); j++)
			cout<<nums[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
//3 sum问题的复杂度是o(n*n)，因此解决方法是先排序，然后挨个遍历，找出满足条件的一组数字
//对于重复的元素，我们要注意过滤，下面标注释的地方是过滤重复元素的方法
vector<vector<int> > threeSum(vector<int>& nums) {
	int length = nums.size();
	vector<vector<int> > result;
	if(length <= 0)
		return result;
	sort(nums.begin(), nums.end());
	int j, k;
	for(int i = 0; i < length - 2; i++) {
		j = i+1;
		k = length - 1;
		//过滤掉重复的元素
		if(i > 0 && nums[i] == nums[i-1]) {
			continue;
		}
		while(j < k) {
			//过滤掉重复的元素
			if(j > i+1 && nums[j] == nums[j-1]) {
				j++;
				continue;
			}
			//过滤掉重复的元素
			if(k < length-1 && nums[k] == nums[k+1]) {
				k--;
				continue;
			}
			if(nums[i] + nums[j] + nums[k] == 0) {
				vector<int> tmp;
				tmp.push_back(nums[i]);
				tmp.push_back(nums[j]);
				tmp.push_back(nums[k]);
				result.push_back(tmp);
				j++;
			} else if(nums[i] + nums[j] + nums[k] < 0) {
				j++;
			} else {
				k--;
			}
		}
	}
	return result;
}

int main() {
	vector<int> nums;
	// nums.push_back(-1);
	// nums.push_back(0);
	// nums.push_back(1);
	// nums.push_back(2);
	// nums.push_back(-1);
	// nums.push_back(-4);

	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);

	vector<vector<int> > result = threeSum(nums);
	printVector(result);
	return 0;
}