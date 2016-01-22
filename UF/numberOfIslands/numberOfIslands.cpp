
//Number of Islands

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//这种方法是尝试用union-find方法进行解决的，但是现在用pair类型做map的key时遇到了问题，但是这种方法还是很值得尝试的
// int Find(vector<int>& parent, int x) {
// 	if(parent[x] == -1)
// 		return x;
// 	return parent[x] = Find(parent, parent[x]);
// }

// void Union(vector<int>& parent, int x, int y) {
// 	int xset = Find(parent, x);
// 	int yset = Find(parent, y);
// 	parent[xset] = yset;
// }

// struct pairhash{
// 	template<class T1, class T2>
// 	size_t operator()(const pair<T1, T2> &x) const{    //为什么去掉最后的const编译无法通过
// 		hash<T1> h1;
// 		hash<T2> h2;
// 		return h1(x.first) ^ h2(x.second);	
// 	}
// };

// int numIslands(vector<vector<char> >& grid) {
// 	if(grid.size() <= 0 || grid[0].size() <= 0)
// 		return 0;
// 	int col = grid.size();
// 	int row = grid[0].size();
// 	int count = 0;
// 	unordered_map<pair<int, int>, int, pairhash> mapping;
// 	for(int i = 0; i < row; i++) {
// 		for(int j = 0; j < col; j++) {
// 			if(grid[i][j] == '1') {
// 				mapping[make_pair(i, j)] = count++;
// 			}
// 		}
// 	}
// 	vector<int> parent(count, -1);
// 	for(int i = 0; i < row; i++) {
// 		for(int j = 0; j < col; j++) {
// 			if(grid[i][j] == '1') {
// 				int tmp = mapping[make_pair(i, j)];
// 				if(i-1 >= 0 && grid[i-1][j] == '1') {
// 					cout<<mapping[make_pair(i-1, j)]<<endl;
// 					Union(parent, mapping[make_pair(i-1, j)], tmp);
// 				}
// 				if(i+1 < row && grid[i+1][j] == '1') {
// 					Union(parent, mapping[make_pair(i+1, j)], tmp);
// 				}
// 				if(j-1 >= 0 && grid[i][j-1] == '1') {
// 					Union(parent, mapping[make_pair(i, j-1)], tmp);
// 				}
// 				if(j+1 < col && grid[i][j+1] == '1') {
// 					Union(parent, mapping[make_pair(i, j+1)], tmp);
// 				}
// 			}
// 		}
// 	}
// 	unordered_set<int> result;
// 	for(int i = 0; i < cout; i++) {
// 		if(result.find(parent[i]) == result.end())
// 			result.insert(parent[i]);
// 	}
// 	return result.size();
// }


//下面的方法是用dfs的方法解决的，思路比较简单，就不详细说明了
void dfs(vector<vector<char> >& grid, int i, int j, int row, int col) {
	grid[i][j] = '0';
	if(i-1 >= 0 && grid[i-1][j] == '1') {
		dfs(grid, i-1, j, row, col);
	}
	if(i+1 < row && grid[i+1][j] == '1') {
		dfs(grid, i+1, j, row, col);	}
	if(j-1 >= 0 && grid[i][j-1] == '1') {
		dfs(grid, i, j-1, row, col);
	}
	if(j+1 < col && grid[i][j+1] == '1') {
		dfs(grid, i, j+1, row, col);
	}
}

int numIslands(vector<vector<char> >& grid) {
	if(grid.size() <= 0 || grid[0].size() <= 0)
		return 0;
	int row = grid.size();
	int col = grid[0].size();
	int result = 0;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(grid[i][j] == '1') {
				dfs(grid, i, j, row, col);
				result++;
			}
		}
	}
	return result;
}

vector<vector<char> > arr2Vec(char arr[][5], int row, int col) {
	vector<vector<char> >result(row, vector<char>(col, '*'));
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			result[i][j] = arr[i][j];
		}
	}
	return result;
}

void printVector(vector<vector<char> >& grid) {
	if(grid.size() <= 0 || grid[0].size() <= 0)
		cout<<"empty vector"<<endl;
	int row = grid.size();
	int col = grid[0].size();
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			cout<<grid[i][j]<<" ";
		cout<<endl;
	}
}

int main() {
	char arr[4][5] = {{'1', '1', '0', '0', '0'},
					  {'1', '1', '0', '0', '0'},
					  {'0', '0', '1', '0', '0'},
					  {'0', '0', '0', '1', '1'}};
	int col = 5;
	int row = 4;
	vector<vector<char> > grid = arr2Vec(arr, row, col);
	int count = numIslands(grid);
	cout<<count<<endl;
	return 0;
}