
//Maximal Rectangle

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//参照：https://siddontang.gitbooks.io/leetcode-solution/content/array/maximal_rectangle.html
int largestRectangleArea(vector<int> &height) {
	if(height.size() == 0)
		return 0;
	stack<int> s;
	height.push_back(0);
	int area = 0;
	int i = 0;
	int length = height.size();
	while(i < length) {
		if(s.empty() || height[s.top()] <= height[i])
			s.push(i++);
		else {
			int tmp = s.top();
			s.pop();
			area = max(area, height[tmp] * (s.empty() ? i : i - s.top() - 1));
		}
	}
	return area;
}


int maximalRectangle(vector<vector<char> >& matrix) {
	if(matrix.size() == 0 || matrix[0].size() == 0)
		return 0;
	int m = matrix.size();
	int n = matrix[0].size();

	vector<vector<int> > height(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(matrix[i][j] == '0')
				height[i][j] = 0;
			else {
				height[i][j] = (i == 0) ? 1 : (height[i-1][j] + 1);
			}
		}
	}
	int maxArea = 0;
	for(int i = 0; i < m; i++) {
		maxArea = max(maxArea, largestRectangleArea(height[i]));
	}
	return maxArea;
}

int main() {
	vector<int> height;
	height.push_back(2);
	height.push_back(1);
	height.push_back(5);
	height.push_back(6);
	height.push_back(2);
	height.push_back(3);
	int result = largestRectangleArea(height);
	cout<<"result: "<<result<<endl;
}