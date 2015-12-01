
//Container With Most Water

#include <iostream>
#include <vector>

using namespace std;

int maxArea1(vector<int>& height) {
	int length = height.size();
	int result = 0;
	if(length <= 0)
		return result;
	int left = 0;
	int right = length - 1;
	while(left < right) {
		result = max(result, min(height[left], height[right]) * (right - left));
		if(height[left] < height[right]) {
			left++;
		} else {
			right--;
		}

	}
	return result;
}

//第二种方式，个人觉得这种方式更容易让人理解
//首先假设我们能找到能取最大容积的纵线为i，j(假设i<j)，则最大容积为：C = min(height[i], height[j]) * (j - i)
//则会有如下两条性质：
//1、在j的右端没有一条线会比它高，假设存在k(j < k && height[k] > height[j])，那么由于height[k] > height[j]
//所以由C' = min(height[i], height[k]) * (k - i) > C，与C是最大值矛盾，所以这个性质得证
//2、同理在i的左边也不会有比它高的线
//所以我们想找到比C更大的值时，需要向中间靠拢，而且新得到的两条线height[i'] >= height[i]，height[j'] >= height[j]
int maxArea(vector<int>& height) {
	int length = height.size();
	int result = 0;
	if(length <= 0)
		return result;
	int left = 0;
	int right = length - 1;
	while(left < right) {
		result = max(result, min(height[left], height[right]) * (right - left));
		if(height[left] < height[right]) {
			int tmp = left;
			while(tmp < right && height[tmp] <= height[left])
				tmp++;
			left = tmp;
		} else {
			int tmp = right;
			while(tmp > left && height[tmp] <= height[right])
				tmp--;
			right = tmp;
		}
	}
	return result;
}

int main() {
	vector<int> height;
	height.push_back(2);
	height.push_back(1);
	height.push_back(5);
	height.push_back(6);
	height.push_back(2);
	height.push_back(3);
	int result = maxArea(height);
	cout<<result<<endl;
	return 0;

}