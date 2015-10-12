
#include <iostream>
#include <vector>

using namespace std;

//注意点：C++会将默认的内存赋值为0，所以在遍历到tmp以外的内存时，也
//有可能被添加进result，所以声明tmp的时候要用1进行初始化，在遍历的
//时候用是否变为0来判断访问过与否
vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> result;
	if(matrix.size() == 0 || matrix[0].size() == 0)
		return result;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int> > tmp(m, vector<int>(n, 1)); 
	for(int i = 0; i < m; i++) {
		for(int j = i; j < n-i; j++) {
			if(tmp[i][j] == 1) {
				result.push_back(matrix[i][j]);
				tmp[i][j] = 0;
			}
		}
		for(int k = i+1; k < m-i; k++) {
			if(tmp[k][n-i-1] == 1) {
				result.push_back(matrix[k][n-i-1]);
				tmp[k][n-i-1] = 0;
			}
		}
		for(int w = n-i-2; w >= i; w--) {
			if(tmp[m-i-1][w] == 1) {
				result.push_back(matrix[m-i-1][w]);
				tmp[m-i-1][w] = 0;
			}
		}
		for(int r = m-i-2; r > i; r--) {
			if(tmp[r][i] == 1) {
				result.push_back(matrix[r][i]);
				tmp[r][i] = 0;
			}
		}
	}
	return result;
}

void printVector(vector<int> &nums) {
	int length = nums.size();
	if(length == 0)
		cout<<"empty vector"<<endl;
	for(int i = 0; i < length; i++) {
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}

void printMatrix(vector<vector<int> > &matrix) {
	if(matrix.size() == 0 || matrix[0].size() == 0)
		cout<<"empty vector"<<endl;
	int m = matrix.size();
	int n = matrix[0].size();
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	vector<vector<int> > nums;
	vector<int> tmp1;
	tmp1.push_back(1);
	// tmp1.push_back(2);
	// tmp1.push_back(3);
	// tmp1.push_back(4);
	nums.push_back(tmp1);

	vector<int> tmp2;
	tmp2.push_back(5);
	// tmp2.push_back(6);
	// tmp2.push_back(7);
	// tmp2.push_back(8);
	nums.push_back(tmp2);

	vector<int> tmp3;
	tmp3.push_back(9);
	// tmp3.push_back(10);
	// tmp3.push_back(11);
	// tmp3.push_back(12);
	nums.push_back(tmp3);

	vector<int> tmp4;
	tmp4.push_back(13);
	nums.push_back(tmp4);
	// printMatrix(nums);
	vector<int> result = spiralOrder(nums);
	printVector(result);
	return 0;
}