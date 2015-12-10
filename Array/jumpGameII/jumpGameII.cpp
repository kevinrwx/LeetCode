
//Jump Game II

#include <iostream>
#include <vector>

using namespace std;

//仍然使用贪心算法，我们维护两个变量，当前能到达的最远点p以及下一次能到达的最远点q，在p的范围内迭代计算q，
//然后更新步数，并将最大的q设置为p，重复这个过程直到p到达终点
int jump(vector<int>& nums) {
	int length = nums.size();
	int res = 0;
	int p = 0;
	int q = 0;

	int i = 0;
	while(i < length) {
		if(p >= length - 1)
			break;
		while(i <= p) {
			q = max(q, i + nums[i]);
			i++;
		}
		p = q;
		res++;
	}
	return res;
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	// nums.push_back(4);
	int result = jump(nums);
	cout<<"jumps: "<<result<<endl;
	return 0;
}