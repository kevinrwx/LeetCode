
//Word Ladder

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

//这是采用DFS方法的解，当数据量很少时，可以计算出正确的答案，但是当数据量很大时，就会超时
// void ladderRec(const string & start, const string & end, unordered_set<string> &dict, unordered_set<string> &unique, int level, int* min_value) {       
//     if(unique.size()==dict.size()) {
//         return;
//     }
        
//     if(level>start.length()) return;
        
//     for(int i=0; i<start.size(); i++) {
//         string temp = start;
//         for(char c='a'; c<='z'; c++) {
//             temp[i] = c;
//             if(temp == end) {
//                 *min_value = min(*min_value, level+2);
//                 return ;
//             }
//             if( dict.find(temp)!=dict.end() && unique.find(temp)==unique.end() ) {
//                 unique.insert(temp);
//                 ladderRec(temp, end, dict, unique, level+1, min_value);  
//                 unique.erase(temp);
//             }
//         }
//     }
// }

// int ladderLength(string start, string end, unordered_set<string> &dict) {
//     int min_value = INT_MAX;
//     unordered_set<string> unique;
        
//     ladderRec(start, end, dict, unique, 0, &min_value);
//     return min_value==INT_MAX ? 0 : min_value;
// }


//这是采用BFS的解，首先思路是正常BFS的思路，同时为了防止重复访问之前已经访问过的单词，我们用一个set来存储之前
//访问过的单词，这样就不会形成单词访问的环
//由于BFS在第一次找到了满足条件的路径时就会返回结果，这样就保证了第一次返回的结果一定是最小值
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
	if(beginWord == endWord)
		return 2;
	int min_value = 0;
	unordered_set<string> unique;
	unique.insert(beginWord);

	queue<string> que;
	que.push(beginWord);
	int q1 = 1;
	int q2 = 0;
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
				if(temp == endWord)
					return min_value+2;
				if(wordList.find(temp) != wordList.end() && unique.find(temp) == unique.end()) {
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
			++min_value;
		}
	}
	return 0;
}

int main() {
	string beginWord = "hit";
	string endWord = "cog";
	unordered_set<string> wordList;
	wordList.insert("hot");
	wordList.insert("dot");
	wordList.insert("dog");
	wordList.insert("lot");
	wordList.insert("log");
	int result = ladderLength(beginWord, endWord, wordList);
	cout<<result<<endl;
	return 0;
}