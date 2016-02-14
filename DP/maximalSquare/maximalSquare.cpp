
//Maximal Square

#include <iostream>
#include <vector>

using namespace std;

//这道题目是dp类型的题目，dp[i][j]表示以(i,j)='1'为右下角的最大正方形的边长
//则递推公式为dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
int maximalSquare(vector<vector<char> >& matrix) {
	if(matrix.size() == 0)
		return 0;
	int row = matrix.size();
	int col = matrix[0].size();
	int maximum = 0;
	vector<vector<int> >ret(row, vector<int>(col, 0));
	//对第一行进行初始化
	for(int i = 0; i < col; i++) {
		ret[0][i] = matrix[0][i] - '0';
		maximum = max(maximum, ret[0][i]);
	}
	//对第一列进行初始化
	for(int j = 0; j < row; j++) {
		ret[j][0] = matrix[j][0] - '0';
		maximum = max(maximum, ret[j][0]);
	}
	for(int i = 1; i < row; i++) {
		for(int j = 1; j < col; j++) {
			if(matrix[i][j] == '1') {
				ret[i][j] = min(ret[i-1][j-1], min(ret[i-1][j], ret[i][j-1])) + 1;
				maximum = max(maximum, ret[i][j]);
			}
		}
	}
	return maximum*maximum;
}

vector<int> arr2vec(int arr[], int n) {
	vector<int> result;
	for(int i = 0; i < n; i++)
		result.push_back(arr[i]);
	return result;
}

int main() {
	int arr[] = {2, 1, 5, 6, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> height = arr2vec(arr, n);
	int result = largestRectangleArea(height);
	cout<<result<<endl;
	return 0;
}