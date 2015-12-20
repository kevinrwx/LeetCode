
//Word Search

#include <iostream>
#include <vector>

using namespace std;

//这道题目仍然是正常回溯题目的应用，不过由于每个元素只能被访问一次，所以需要用一个isVisited数组标示这个元素有没有被访问过
//而且是每次确定进行下一层递归时，才将这个元素置为true，在将这个元素上、下、左、右的四个元素添加到tmp数组时，并不
//将这些元素设置为true
void backtrack(vector<vector<char> >& board, vector<pair<int, int> >& next, int k, string word, vector<vector<bool> >& isVisited, bool* finalRes) {
	if(k == word.length()) {
		*finalRes = true;
	}
	else {
		for(int i = 0; i < next.size(); i++) {
			int x = next[i].first;
			int y = next[i].second;
			isVisited[x][y] = true;
			vector<pair<int, int> > tmp;
			if(x-1 >= 0 && board[x-1][y] == word[k] && !isVisited[x-1][y]) {
				tmp.push_back(pair<int, int>(x-1, y));
			}
			if(y-1 >= 0 && board[x][y-1] == word[k] && !isVisited[x][y-1]) {
				tmp.push_back(pair<int, int>(x, y-1));
			}
			if(x+1 < board.size() && board[x+1][y] == word[k] && !isVisited[x+1][y]) {
				tmp.push_back(pair<int, int>(x+1, y));
			}
			if(y+1 < board[0].size() && board[x][y+1] == word[k] && !isVisited[x][y+1]) {
				tmp.push_back(pair<int, int>(x, y+1));
			}
			if(tmp.size() == 0) {
				//对于不符合条件的情况，在跳出此次循环时，仍需要将isVisited[x][y]置为false
				isVisited[x][y] = false;
				continue;
			}
			backtrack(board, tmp, k+1, word, isVisited, finalRes);
			//如果找到符合条件的情况，就不必接着进行循环了，可以跳出循环，增加这个判断以后，程序不会超时
			if(*finalRes == true)
				break;
			isVisited[x][y] = false;
		}
	}
}

bool exist(vector<vector<char> >& board, string word) {
	if(word.length() == 0 || board.size() == 0 || board[0].size() == 0)
		return false;
	vector<pair<int, int> > next;
	bool result = false;
	bool finalRes = false;
	vector<vector<bool> >isVisited(board.size(), vector<bool>(board[0].size(), false));
	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[i].size(); j++)
			if(board[i][j] == word[0]) {
				next.push_back(pair<int, int>(i, j));
				result = true;
			}
	}
	backtrack(board, next, 1, word, isVisited, &finalRes);
	return result && finalRes;
}

int main() {
	vector<vector<char> > board;
	// vector<char> tmp1;
	// tmp1.push_back('A');
	// tmp1.push_back('B');
	// tmp1.push_back('C');
	// tmp1.push_back('E');
	// vector<char> tmp2;
	// tmp2.push_back('S');
	// tmp2.push_back('F');
	// tmp2.push_back('C');
	// tmp2.push_back('S');
	// vector<char> tmp3;
	// tmp3.push_back('A');
	// tmp3.push_back('D');
	// tmp3.push_back('E');
	// tmp3.push_back('E');
	// board.push_back(tmp1);
	// board.push_back(tmp2);
	// board.push_back(tmp3);

	vector<char> tmp1;
	tmp1.push_back('C');
	tmp1.push_back('A');
	tmp1.push_back('A');
	vector<char> tmp2;
	tmp2.push_back('A');
	tmp2.push_back('A');
	tmp2.push_back('A');
	vector<char> tmp3;
	tmp3.push_back('B');
	tmp3.push_back('C');
	tmp3.push_back('D');
	board.push_back(tmp1);
	board.push_back(tmp2);
	board.push_back(tmp3);

	
	string str = "AAB";
	if(exist(board, str))
		cout<<"exist";
	else
		cout<<"not exist";
	cout<<endl;
	return 0;
}




