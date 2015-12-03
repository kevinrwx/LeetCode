
//Trapping Rain Water

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//在将整个水槽填满雨水以后，水槽连带雨水的结果会呈现一个塔形，因此我们可以先找到塔的最高点，然后依次从左右进行遍历
int trap(vector<int>& height) {
	int length = height.size();
	int result = 0;
	if(length <= 2)
		return result;
	int maximum = -1;
	int maxId = 0;
	//先找到全局最高点，并记录下该点的index值
	for(int i = 0; i < length; i++) {
		if(height[i] >= maximum) {
			maximum = height[i];
			maxId = i;
		}
	}
	//从左遍历到maxId，记录雨水的量
	int left = height[0];
	for(int i = 0; i < maxId; i++) {
		if(height[i] >= left) {
			left = height[i];
		} else {
			result += (left - height[i]);
		}
	}
	//从右遍历到maxId，记录雨水的量
	int right = height[length - 1];
	for(int i = length - 1; i > maxId; i--) {
		if(height[i] >= right) {
			right = height[i];
		} else {
			result += (right - height[i]);
		}
	}
	return result;
}

int main() {
	vector<int> height;
	height.push_back(0);
	height.push_back(1);
	height.push_back(0);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);
	height.push_back(1);
	height.push_back(3);
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);
	height.push_back(1);
	int result = trap(height);
	cout<<result<<endl;
	return 0;

}