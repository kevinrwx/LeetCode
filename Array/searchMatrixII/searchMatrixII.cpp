
//Search a 2D Matrix II

#include <iostream>
#include <vector>

using namespace std;

//这道题目任然采用了二分查询的思想，每次排除掉一行或者是一列，每次判断右上角和target的值，来决定舍去最上面一行还是最右面一列；
bool searchMatrix(vector<vector<int> >& matrix, int target) {
	if(matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int m = matrix.size();
	int n = matrix[0].size();
	int i = 0;
	int j = n-1;
	while(i < m && j >= 0) {
		if(matrix[i][j] == target)
			return true;
		else if(matrix[i][j] > target) {
			j--;
		} else {
			i++;
		}
	}
	return false;
}

int main() {
	vector<vector<int> > matrix;
	vector<int> tmp1;
	tmp1.push_back(1);
	tmp1.push_back(4);
	tmp1.push_back(7);
	tmp1.push_back(11);
	tmp1.push_back(15);
	vector<int> tmp2;
	tmp2.push_back(2);
	tmp2.push_back(5);
	tmp2.push_back(8);
	tmp2.push_back(12);
	tmp2.push_back(19);
	vector<int> tmp3;
	tmp3.push_back(3);
	tmp3.push_back(6);
	tmp3.push_back(9);
	tmp3.push_back(16);
	tmp3.push_back(22);
	vector<int> tmp4;
	tmp4.push_back(10);
	tmp4.push_back(13);
	tmp4.push_back(14);
	tmp4.push_back(17);
	tmp4.push_back(24);
	vector<int> tmp5;
	tmp5.push_back(18);
	tmp5.push_back(21);
	tmp5.push_back(23);
	tmp5.push_back(26);
	tmp5.push_back(30);
	matrix.push_back(tmp1);
	matrix.push_back(tmp2);
	matrix.push_back(tmp3);
	matrix.push_back(tmp4);
	matrix.push_back(tmp5);

	int target = 5;
	bool result = searchMatrix(matrix, target);
	if(result) 
		cout<<"true";
	else
		cout<<"false";
	cout<<endl;
	return 0;
}