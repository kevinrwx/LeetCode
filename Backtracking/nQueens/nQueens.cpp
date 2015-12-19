
//N-Queens

#include <iostream>
#include <vector>

using namespace std;

bool is_collision(vector<string>& tmp, int x, int y) {
	for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--)
		if(tmp[i][j] == 'Q')
			return true;
	for(int i = x-1, j = y+1; i >= 0 && j < tmp.size(); i--, j++)
		if(tmp[i][j] == 'Q')
			return true;
	return false;
}

//主要参照八皇后问题的代码
void backtrack(vector<vector<string> >& result, vector<string>& tmp, int k, vector<int>& candidates) {
	if(k == tmp.size()) {
		result.push_back(tmp);
	}
	else {
		for(int i = 0; i < tmp.size(); i++) {
			if(candidates[i] == 1 || is_collision(tmp, k, i))
				continue;
			tmp[k][i] = 'Q';
			candidates[i] = 1;
			backtrack(result, tmp, k+1, candidates);
			tmp[k][i] = '.';
			candidates[i] = 0;
		}
	}
}

vector<vector<string> > solveNQueens(int n) {
	if(n <= 0)
		return vector<vector<string> >();
	vector<vector<string> > result;
	vector<string> tmp(n, string(n, '.'));
	vector<int> candidates(n, 0);
	backtrack(result, tmp, 0, candidates);
	return result;

}

void printVector(vector<vector<string> >& result) {
	int length = result.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++) {
		for(int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<endl;
		cout<<endl;
	}
}

int main() {
	int n = 4;
	vector<vector<string> > result = solveNQueens(n);
	printVector(result);
	return 0;
}



//八皇后问题的代码

// #include <iostream>
// #include <vector>

// using namespace std;

// bool is_collision(vector<vector<int> >& matrix, int x, int y) {
// 	for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--)
// 		if(matrix[i][j] == 1)
// 			return true;
// 	for(int i = x-1, j = y+1; i >= 0 && y < matrix.size(); i--, j++)
// 		if(matrix[i][j] == 1)
// 			return true;
// 	return false;
// }

// void backtrack(vector<vector<int> >& matrix, int k, vector<int>& candidates) {
// 	if(k == matrix.size()) {
// 		for(int i = 0; i < matrix.size(); i++) {
// 			for(int j = 0; j < matrix[i].size(); j++)
// 				cout<<matrix[i][j]<<" ";
// 			cout<<endl;
// 		}
// 		cout<<"haha"<<endl;
// 	} else {
// 		for(int j = 0; j < matrix.size(); j++) {
// 			if(candidates[j] == 1 || is_collision(matrix, k, j))
// 				continue;
// 			matrix[k][j] = 1;
// 			candidates[j] = 1;
// 			backtrack(matrix, k+1, candidates);
// 			matrix[k][j] = 0;
// 			candidates[j] = 0;
// 		}
// 	}
// }

// void solveNQueens(int n) {
// 	vector<vector<int> > matrix(n, vector<int>(n, 0));
// 	vector<int> candidates(n, 0);
// 	backtrack(matrix, 0, candidates);
// }

// int main() {
// 	int n = 8;
// 	solveNQueens(n);
// 	return 0;
// }









