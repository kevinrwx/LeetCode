
//Edit Distance

#include <iostream>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
	int row = word1.length() + 1;
	int col = word2.length() + 1;
	//声明vector
	//vector<T> v(n, i); v是包含n个值为i的向量
	//vector<T> v(n); v是包含n个元素的向量
	//或者可以直接声明为 vector<vector<int> > result(row, vector<int>(col)); 这种声明方法与下面的方法等价
	vector<int> tmp(col);
	vector<vector<int> > result(row, tmp);

	//然后对result做初始化，result[0][0..j..col] = j; result[0..i..row][0] = i;
	for(int i = 0; i < row; i++)
		result[i][0] = i;
	for(int j = 0; j < col; j++)
		result[0][j] = j;
	
	//根据递推公式进行处理
	//递推公式为：d[i,j] = min(d[i,j-1], d[i-1,j], d[i-1,j-1] + num) num为0或1 如果word1[i] == word2[j]，num为0，否则num为1
	for(int i = 1; i < row; i++) {
		for(int j = 1; j < col; j++) {
			if(word1[i-1] == word2[j-1])
				result[i][j] = result[i-1][j-1];
			else
				result[i][j] = result[i-1][j-1] + 1;
			result[i][j] = min(result[i][j], min(result[i-1][j] + 1, result[i][j-1] + 1));
		}
	}
	return result[row-1][col-1];
}

int main() {
	string word1 = "sunday";
	string word2 = "saturday";
	int result = minDistance(word1, word2);
	cout<<"result: "<<result<<endl;
	return 0;
}