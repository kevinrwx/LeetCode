
//Minimum Path Sum

#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int> >& grid) {
	int m = grid.size();
	int n = grid[0].size();
	int sum = 0;
	if(m == 1) {
		for(int i = 0; i < n; i++)
			sum += grid[0][i];
		return sum;
	}
	if(n == 1) {
		for(int i = 0; i < m; i++)
			sum += grid[i][0];
		return sum;
	}
	vector<int> tmp;
	tmp.push_back(10000);
	int temp = 0;
	for(int i = 1; i <= n; i++) {
		temp += grid[0][i-1];
		tmp.push_back(temp);
	}
		tmp.push_back(0);
	for(int i = 1; i < m; i++) {
		cout<<"hehe"<<endl;
		for(int j = 0; j < n; j++) {
			int minimum = min(tmp[j] + grid[i][j], tmp[j+1] + grid[i][j]);
			tmp[j+1] = minimum;
			cout<<tmp[j+1]<<" ";
		}
	}
	sum = tmp[n];
	return sum;
}

int main() {
	vector<vector<int> > grid;
	vector<int> tmp1;
	tmp1.push_back(1);
	tmp1.push_back(2);
	tmp1.push_back(3);
	vector<int> tmp2;
	tmp2.push_back(4);
	tmp2.push_back(5);
	tmp2.push_back(6);
	vector<int> tmp3;
	tmp3.push_back(7);
	tmp3.push_back(8);
	tmp3.push_back(9);
	grid.push_back(tmp1);
	grid.push_back(tmp2);
	grid.push_back(tmp3);
	int result = minPathSum(grid);
	cout<<"Result: "<<result<<endl;
	return 0;
}

