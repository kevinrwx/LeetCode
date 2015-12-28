
//word search II

#include <iostream>
#include <vector>
#include <set>

#define ALPHABET_SIZE 26

using namespace std;

//这道题目需要用到的Trie树的代码
struct TrieNode {
	bool leaf;
	TrieNode* children[ALPHABET_SIZE];
	TrieNode() {
		leaf = false;
		for(int i = 0; i < ALPHABET_SIZE; i++)
			children[i] = NULL;
	}
};

struct Trie {
	TrieNode* root;
	int count;
	Trie() {
		root = new TrieNode();
		count = 0;
	}
};

void insert(Trie* pTrie, string word) {
	TrieNode* pCrawl = pTrie->root;
	pTrie->count++;
	int level;
	int index;
	int length = word.size();
	for(level = 0; level < length; level++) {
		index = word[level] - 'a';
		if(pCrawl->children[index] == NULL)
			pCrawl->children[index] = new TrieNode();
		pCrawl = pCrawl->children[index];
	}
	pCrawl->leaf = true;
}

bool search(Trie* pTrie, string word) {
	TrieNode* pCrawl = pTrie->root;
	int level;
	int index;
	int length = word.size();
	for(level = 0; level < length; level++) {
		index = word[level] - 'a';
		if(pCrawl->children[index] == NULL)
			return false;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->leaf);
}

bool startsWith(Trie* pTrie, string prefix) {
	TrieNode* pCrawl = pTrie->root;
	int level;
	int index;
	int length = prefix.length();
	for(level = 0; level < length; level++) {
		index = prefix[level] - 'a';
		if(pCrawl->children[index] == NULL)
			return false;
		pCrawl = pCrawl->children[index];
	}
	return true;
}

//这道题目仍然采用了回溯的思想，但是中间结合着Trie树进行了剪枝，这样大大降低了回溯的深度，减少了需要运行的时间
void backtrack(vector<vector<char> >& board, vector<vector<bool> >& isVisited, Trie* pTrie, int i, int j, string tmp, set<string>& result) {
	//第一次提交时，由于忘了写isVisited[i][j]的判断，导致程序的运行时间变得很长，这个需要注意
	if(i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1 || isVisited[i][j])
		return ;
	tmp.push_back(board[i][j]);
	isVisited[i][j] = true; 
	if(startsWith(pTrie, tmp)) {
		if(search(pTrie, tmp))
			result.insert(tmp);
		backtrack(board, isVisited, pTrie, i-1, j, tmp, result);
		backtrack(board, isVisited, pTrie, i+1, j, tmp, result);
		backtrack(board, isVisited, pTrie, i, j-1, tmp, result);
		backtrack(board, isVisited, pTrie, i, j+1, tmp, result);
	}
	tmp.pop_back();
	isVisited[i][j] = false;
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
	int length = words.size();
	vector<string> result;
	if(board.size() == 0 || board[0].size() == 0 || words.size() == 0)
		return result;
	Trie* pTrie = new Trie();
	for(int i = 0; i < length; i++)
		insert(pTrie, words[i]);
	vector<vector<bool> >isVisited(board.size(), vector<bool>(board[0].size(), false));
	string tmp;
	set<string> res;
	for(int i = 0; i < board.size(); i++)
		for(int j = 0; j < board[0].size(); j++)
			backtrack(board, isVisited, pTrie, i, j, tmp, res);
	set<string>::iterator it;
	for(it = res.begin(); it != res.end(); it++)
		result.push_back(*it);
	return result;
}

int main() {
	// vector<vector<char> > board;
	// vector<char> tmp1;
	// tmp1.push_back('o');
	// tmp1.push_back('a');
	// tmp1.push_back('a');
	// tmp1.push_back('n');
	// vector<char> tmp2;
	// tmp2.push_back('e');
	// tmp2.push_back('t');
	// tmp2.push_back('a');
	// tmp2.push_back('e');
	// vector<char> tmp3;
	// tmp3.push_back('i');
	// tmp3.push_back('h');
	// tmp3.push_back('k');
	// tmp3.push_back('r');
	// vector<char> tmp4;
	// tmp4.push_back('i');
	// tmp4.push_back('f');
	// tmp4.push_back('l');
	// tmp4.push_back('v');
	// board.push_back(tmp1);
	// board.push_back(tmp2);
	// board.push_back(tmp3);
	// board.push_back(tmp4);

	// vector<string> words;
	// words.push_back("oath");
	// words.push_back("oath");
	// words.push_back("oath");
	// words.push_back("pea");
	// words.push_back("eat");
	// words.push_back("rain");

	vector<vector<char> > board;
	vector<char> tmp1;
	tmp1.push_back('a');
	tmp1.push_back('a');
	tmp1.push_back('a');
	tmp1.push_back('a');
	vector<char> tmp2;
	tmp2.push_back('a');
	tmp2.push_back('a');
	tmp2.push_back('a');
	tmp2.push_back('a');
	vector<char> tmp3;
	tmp3.push_back('a');
	tmp3.push_back('a');
	tmp3.push_back('a');
	tmp3.push_back('a');
	board.push_back(tmp1);
	board.push_back(tmp2);
	board.push_back(tmp3);

	vector<string> words;
	words.push_back("aaaaaaaaaaaa");
	words.push_back("aaaaaaaaaaaa");
	words.push_back("aaaaaaaaaaab");

	vector<string> result = findWords(board, words);
	for(int i = 0; i < result.size(); i++)
		cout<<result[i]<<" ";
	cout<<endl;
	return 0;
}
