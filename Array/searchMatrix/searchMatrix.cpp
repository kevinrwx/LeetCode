
//Search a 2D Matrix

#include <iostream>
#include <vector>

using namespace std;

//仍然使用常规的二分搜索法，只不过在获取中间元素时，要做一下变化，由一维数组的matrix[mid]变成二维数组的matrix[mid / n][mid % n]
bool searchMatrix(vector<vector<int> >& matrix, int target) {
	if(matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int m = matrix.size();
	int n = matrix[0].size();
	int left = 0;
	int right = m*n - 1;
	int mid;
	while(left <= right) {
		mid = left + (right - left) / 2;
		if(target == matrix[mid / n][mid % n])
			return true;
		else if(target < matrix[mid / n][mid % n]) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return false;
}

int main() {
	vector<vector<int> > matrix;
	vector<int> tmp1;
	tmp1.push_back(1);
	tmp1.push_back(3);
	tmp1.push_back(5);
	tmp1.push_back(7);
	vector<int> tmp2;
	tmp2.push_back(10);
	tmp2.push_back(11);
	tmp2.push_back(16);
	tmp2.push_back(20);
	vector<int> tmp3;
	tmp3.push_back(23);
	tmp3.push_back(30);
	tmp3.push_back(34);
	tmp3.push_back(50);
	matrix.push_back(tmp1);
	matrix.push_back(tmp2);
	matrix.push_back(tmp3);

	int target = 3;

	bool result = searchMatrix(matrix, target);
	if(result)
		cout<<"true";
	else
		cout<<"false";
	cout<<endl;
	return 0;
}