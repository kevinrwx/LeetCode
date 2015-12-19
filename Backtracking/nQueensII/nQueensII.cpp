

//N-Queens II

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

void backtrack(int* num, vector<string>& tmp, int k, vector<int>& candinates) {
	if(k == tmp.size()) {
		(*num) += 1;
	}
	else {
		for(int i = 0; i < tmp.size(); i++) {
			if(candinates[i] == 1 || is_collision(tmp, k, i))
				continue;
			tmp[k][i] = 'Q';
			candinates[i] = 1;
			backtrack(num, tmp, k+1, candinates);
			tmp[k][i] = '.';
			candinates[i] = 0;
		}
	}
}

int totalNQueens(int n) {
    int num = 0;
    vector<string> tmp(n, string(n, '.'));
    vector<int> candinates(n, 0);
    backtrack(&num, tmp, 0, candinates);
    return num;
}

int main() {
    int n = 5;
    int result = totalNQueens(n);
    cout<<result<<endl;
    return 0;
}
