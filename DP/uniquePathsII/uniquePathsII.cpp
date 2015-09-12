
//Unique Paths II

#include <iostream>
#include <vector>

using namespace std;

//要注意m和n分别代表的是什么，m代表的是行数，n代表的是每一行有多少数字
int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	if(m == 1) {
		for(int i = 0; i < n; i++)
			if(obstacleGrid[0][i] == 1)
				return 0;
		return 1;
	}
	if(n == 1) {
		for(int i = 0; i < m; i++)
			if(obstacleGrid[i][0] == 1)
				return 0;
		return 1;
	}
	int* tmp = new int[n+1];
	tmp[0] = 0;
	bool init = true;
	for(int i = 1; i <= n; i++) {
		if(obstacleGrid[0][i-1] == 0 && init) {
			tmp[i] = 1;
		}
		else {
			tmp[i] = 0;
			init = false;
		}
	}
	for(int i = 2; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(obstacleGrid[i-1][j-1] == 1)
				tmp[j] = 0;
			else
				tmp[j] = tmp[j] + tmp[j-1];
		}
	}
	int result = tmp[n];
	delete[] tmp;
	return result;
}

int main() {
	vector<vector<int> > obstacleGrid;
	vector<int> tmp1;
	tmp1.push_back(0);
	tmp1.push_back(1);
	tmp1.push_back(0);
	tmp1.push_back(0);
	tmp1.push_back(0);
	vector<int> tmp2;
	tmp2.push_back(1);
	tmp2.push_back(0);
	tmp2.push_back(0);
	tmp2.push_back(0);
	tmp2.push_back(0);
	vector<int> tmp3;
	tmp3.push_back(0);
	tmp3.push_back(0);
	tmp3.push_back(0);
	tmp3.push_back(0);
	tmp3.push_back(0);
	obstacleGrid.push_back(tmp1);
	obstacleGrid.push_back(tmp2);
	obstacleGrid.push_back(tmp3);
	obstacleGrid.push_back(tmp3);
	int result = uniquePathsWithObstacles(obstacleGrid);
	cout<<result<<endl;
	return 0;
}











