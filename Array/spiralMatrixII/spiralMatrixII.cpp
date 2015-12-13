
//Spiral Matrix II

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<vector<int> >& nums) {
	int length = nums.size();
	for(int i = 0; i < length; i++) {
		for(int j = 0; j < nums[i].size(); j++)
			cout<<nums[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
//注意螺旋遍历矩阵的方法
vector<vector<int> > generateMatrix(int n) {
	vector<vector<int> > result(n, vector<int>(n, 0));
	int index = 1;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n-i; j++) {
			if(result[i][j] == 0)
				result[i][j] = index++;
		}
		for(int k = i+1; k < n-i; k++) {
			if(result[k][n-i-1] == 0)
				result[k][n-i-1] = index++;
		}
		for(int w = n-i-2; w >= i; w--) {
			if(result[n-i-1][w] == 0)
				result[n-i-1][w] = index++;
		}
		for(int r = n-i-2; r > i; r--) {
			if(result[r][i] == 0)
				result[r][i] = index++;
		}
	}
	return result;
}

int main() {
	int n = 3;
	vector<vector<int> > result = generateMatrix(n);
	printVector(result);
	return 0;
}