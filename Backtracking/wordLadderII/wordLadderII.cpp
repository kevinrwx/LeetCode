
//word ladder II

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

// void getParents(vector<string>& tmp, unordered_map<string, string>& parent, string target) {
// 	for(string cur = target; parent.find(cur) != parent.end(); cur = parent.at(cur))
// 		tmp.push_back(cur);
// 	reverse(tmp.begin(), tmp.end());
// }

// vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
// 	vector<vector<string> > result;
// 	if((beginWord == endWord) || beginWord.length() <= 1) {
// 		vector<string> tmp;
// 		tmp.push_back(beginWord);
// 		tmp.push_back(endWord);
// 		result.push_back(tmp);
// 		return result;
// 	}
// 	unordered_set<string> unique;
// 	unordered_map<string, string> parent;
// 	unique.insert(beginWord);
// 	parent[beginWord] = "beginWord";
// 	queue<string> que;
// 	int q1 = 1;
// 	int q2 = 0;

// 	int level = 0;
// 	int min_value = INT_MAX;

// 	que.push(beginWord);

// 	while(q1 > 0) {
// 		string s = que.front();
// 		que.pop();
// 		--q1;

// 		for(int i = 0; i < s.length(); i++) {
// 			string temp = s;
// 			for(char c = 'a'; c <= 'z'; c++) {
// 				if(temp[i] == c)
// 					continue;
// 				temp[i] = c;
// 				if(temp == endWord) {
// 					parent[temp] = s;
// 					vector<string> tmp;
// 					getParents(tmp, parent, endWord);
// 					if(min_value >= tmp.size())
// 						result.push_back(tmp);
// 					min_value = min(min_value, level+2);
// 					continue;
// 				}
// 				if(wordList.find(temp) != wordList.end() && unique.find(temp) == unique.end()) {
// 					parent[temp] = s;
// 					unique.insert(temp);
// 					que.push(temp);
// 					q2++;
// 				}
// 			}
// 		}
// 		if(q1 == 0) {
// 			q1 = q2;
// 			q2 = 0;
// 			++level;
// 		}
// 	}
// 	return result;
// }

void getParents(vector<string>& tmp, unordered_map<string, string>& parent, string target) {
	for(string cur = target; parent.find(cur) != parent.end(); cur = parent.at(cur))
		tmp.push_back(cur);
	reverse(tmp.begin(), tmp.end());
}
//这道题目我并没有解决出来，这道题目还是像word ladder一样，采用BFS的思想，只不过这道题目是求路径本身，不是求路径
//长度，所以这道题在记录前驱和判重的地方与普通的广搜不同
// 这道题目还需要继续思考，希望在第二遍做时能解决出来
vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
	vector<vector<string> > result;
	if((beginWord == endWord) || beginWord.length() <= 1) {
		vector<string> tmp;
		tmp.push_back(beginWord);
		tmp.push_back(endWord);
		result.push_back(tmp);
		return result;
	}
	unordered_set<string> unique;
	unordered_map<string, string> parent;
	unique.insert(beginWord);
	parent[beginWord] = "beginWord";
	queue<string> que;
	int q1 = 1;
	int q2 = 0;

	que.push(beginWord);

	while(q1 > 0) {
		string s = que.front();
		que.pop();
		--q1;

		for(int i = 0; i < s.length(); i++) {
			string temp = s;
			for(char c = 'a'; c <= 'z'; c++) {
				if(temp[i] == c)
					continue;
				temp[i] = c;
				if(temp == endWord) {
					parent[temp] = s;
					vector<string> tmp;
					getParents(tmp, parent, endWord);
					result.push_back(tmp);
					continue;
				}
				if(wordList.find(temp) != wordList.end() && unique.find(temp) == unique.end()) {
					parent[temp] = s;
					unique.insert(temp);
					que.push(temp);
					cout<<temp<<" ";
					q2++;
				}
			}
		}
		cout<<endl;
		if(q1 == 0) {
			q1 = q2;
			q2 = 0;
		}
	}
	return result;
}

void printVector(vector<vector<string> >& result) {
	int length = result.size();
	if(length <= 0)
		cout<<"empty vector"<<endl;
	for(int i = 0; i < length; i++) {
		for(int j = 0; j < result[i].size(); j++) {
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}

unordered_set<string> array2Set(string arr[], int n) {
	unordered_set<string> result;
	for(int i = 0; i < n; i++)
		result.insert(arr[i]);
	return result;
}

// "red"
// "tax"
// ["ted","tex","red","tax","tad","den","rex","pee"]
int main() {
	string beginWord = "red";
	string endWord = "tax";
	string arr[] = {"ted","tex","red","tax","tad","den","rex","pee"};
	int n = sizeof(arr) / sizeof(arr[0]);
	unordered_set<string> wordList = array2Set(arr, n);
	vector<vector<string> > result = findLadders(beginWord, endWord, wordList);
	printVector(result);
	return 0;
}


