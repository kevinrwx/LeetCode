
//Valid Sudoku

#include <iostream>
#include <vector>

using namespace std;

//思路是分别确定每一行、每一列和每一个九宫格不会有重复元素，因此分别遍历每行、每列和每个九宫格就行了
//这道题目还有可以继续优化的地方，把两次二重循环优化成一次二重循环，不过这里面涉及一些怎样在遍历时访
//问九宫格的技巧，因此我就没有继续优化它
bool isValidSudoku(vector<vector<char> >& board) {
	if(board.size() == 0 || board[0].size() == 0)
		return false;
	bool row[9];
	bool col[9];
	for(int i = 0; i < board.size(); i++) {
		memset(row, false, sizeof(bool)*9);
		memset(col, false, sizeof(bool)*9);
		for(int j = 0; j < board[0].size(); j++) {
			if(board[i][j] != '.') {
				if(row[board[i][j] - '1'] == true)
					return false;
				else
					row[board[i][j] - '1'] = true;
			}
			if(board[j][i] != '.') {
				if(col[board[j][i] - '1'] == true)
					return false;
				else
					col[board[j][i] - '1'] = true;
			}
		}
	}
	bool square[9];
	for(int i = 0; i < board.size(); i += 3) {
		for(int j = 0; j < board[0].size(); j += 3) {
			memset(square, false, sizeof(bool)*9);
			for(int u = 0; u < 3; u++) {
				for(int v = 0; v < 3; v++) {
					if(board[i+u][j+v] != '.') {
						if(square[board[i+u][j+v] - '1'] == true)
							return false;
						else
							square[board[i+u][j+v] - '1'] = true;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	//
	return 0;
}