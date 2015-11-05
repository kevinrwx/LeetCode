
//word break

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

//主要是参考https://siddontang.gitbooks.io/leetcode-solution/content/greedy/word_break.html
//具体的思路是：假设dp(i)表示长度为i的字符串能否被切分，则相应的递归方程为：dp(i) = dp(j) && s[j, i) in wordDict
bool wordBreak(string s, unordered_set<string>& wordDict) {
	int length = s.length();
	vector<bool> results(length+1, false);
	results[0] = true;
	unordered_set<string>::iterator it;
	for(int i = 1; i <= length; i++) {
		for(int j = i-1; j >= 0; j--) {
			if(results[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
				results[i] = true;
				break;
			}
		}
	}
	return results[length];
}

int main() {
	string s = "leetcode";
	unordered_set<string> wordDict;
	wordDict.insert("leet");
	wordDict.insert("code");
	bool result = wordBreak(s, wordDict);
	if(result)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}





