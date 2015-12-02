
//rotate image

#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void rotate(vector<vector<int> >& matrix) {
	int n = matrix.size();
	// 沿着斜对角线交换元素
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - 1 - i; j++) {
			swap(&matrix[i][j], &matrix[n - 1 - j][n - 1 - i]);
		}
	}
	//沿着横向中线交换元素
	for(int i = 0; i < n/2; i++) {
		for(int j = 0; j < n; j++) {
			swap(&matrix[i][j], &matrix[n - 1 - i][j]);
		}
	}
}

void printMatrix(vector<vector<int> >& matrix) {
	int n = matrix.size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main() {
	vector<vector<int> > matrix;
	vector<int> tmp1;
	tmp1.push_back(7);
	tmp1.push_back(8);
	tmp1.push_back(9);
	vector<int> tmp2;
	tmp2.push_back(4);
	tmp2.push_back(5);
	tmp2.push_back(6);
	vector<int> tmp3;
	tmp3.push_back(1);
	tmp3.push_back(2);
	tmp3.push_back(3);
	matrix.push_back(tmp3);
	matrix.push_back(tmp2);
	matrix.push_back(tmp1);
	printMatrix(matrix);
	rotate(matrix);
	printMatrix(matrix);
	return 0;
}