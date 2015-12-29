
//Sudoku Solver

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<vector<char> >& board) {
	if(board.empty() || board[0].empty())
		cout<<"empty board"<<endl;
	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[0].size(); j++) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool check(vector<vector<char> >& board, int row, int col) {
	for(int i = 0; i < 9; i++) {
		if(i != row && board[i][col] == board[row][col])
			return false;
		if(i != col && board[row][i] == board[row][col])
			return false;
	}
	int gridx = row/3*3;
	int gridy = col/3*3;
	for(int i = gridx; i < gridx+3; i++) {
		for(int j = gridy; j < gridy+3; j++) {
			if(i != row && j != col)
				if(board[i][j] == board[row][col])
					return false;
		}
	}
	return true;
}
//这道题目太麻烦了，很难测试，需要写代码一遍过
bool backtrack(vector<vector<char> >& board) {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			if(board[i][j] == '.') {
				for(int k = 1; k <= 9; k++) {
					board[i][j] = k + '0';
					if(check(board, i, j) && backtrack(board))
						return true;
					board[i][j] = '.';
				}
				return false;
			}
		}
	}
	return true;
} 

void solveSudoku(vector<vector<char> >& board) {
	backtrack(board);
}

int main() {
	vector<vector<char> > board;
	char c1[] = {'.','.','9','7','4','8','.','.','.'};
	vector<char> v1(c1, c1 + sizeof(c1)/sizeof(char));
	board.push_back(v1);
	char c2[] = {'7','.','.','.','.','.','.','.','.'};
	vector<char> v2(c2, c2 + sizeof(c2)/sizeof(char));
	board.push_back(v2);
	char c3[] = {'.','2','.','1','.','9','.','.','.'};
	vector<char> v3(c3, c3 + sizeof(c3)/sizeof(char));
	board.push_back(v3);
	char c4[] = {'.','.','7','.','.','.','2','4','.'};
	vector<char> v4(c4, c4 + sizeof(c4)/sizeof(char));
	board.push_back(v4);
	char c5[] = {'.','6','4','.','1','.','5','9','.'};
	vector<char> v5(c5, c5 + sizeof(c5)/sizeof(char));
	board.push_back(v5);
	char c6[] = {'.','9','8','.','.','.','3','.','.'};
	vector<char> v6(c6, c6 + sizeof(c6)/sizeof(char));
	board.push_back(v6);
	char c7[] = {'.','.','.','8','.','3','.','2','.'};
	vector<char> v7(c7, c7 + sizeof(c7)/sizeof(char));
	board.push_back(v7);
	char c8[] = {'.','.','.','.','.','.','.','.','6'};
	vector<char> v8(c8, c8 + sizeof(c8)/sizeof(char));
	board.push_back(v8);
	char c9[] = {'.','.','.','.','2','7','5','9','.'};
	vector<char> v9(c9, c9 + sizeof(c9)/sizeof(char));
	board.push_back(v9);
	// printVector(board);
	solveSudoku(board);
	return 0;
}