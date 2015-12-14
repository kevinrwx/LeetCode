
//Minimum Window Substring

#include <iostream>
#include <unordered_map>

using namespace std;

//这种方法的复杂度是o(m*n)，最后提交的时候会超时，因此这种方法需要优化
// string minWindow(string s, string t) {
// 	string result = "ha";
// 	int sLength = s.length();
// 	int tLength = t.length();
// 	int left = sLength;
// 	int right = 0;
// 	int num = 0;
// 	int minWindow = INT_MAX;
// 	unordered_map<char, int> mapping;
// 	for(int i = 0; i < tLength; i++) {
// 		mapping[t[i]] = -1;
// 	}
// 	for(int i = 0; i < sLength; i++) {
// 		if(mapping.find(s[i]) != mapping.end()) {
// 			if(mapping[s[i]] == -1) {
// 				num++;
// 				mapping[s[i]] = i;
// 				left = min(left, i);
// 				right = max(right, i);
// 			} else {
// 				int tmp = i;
// 				for(int j = 0; j < tLength; j++) {
// 					if(mapping[t[j]] > mapping[s[i]]) 
// 						tmp = min(tmp, mapping[t[j]]);
// 				}
// 				left = tmp;
// 				mapping[s[i]] = i;
// 			}
// 		}
// 		if(num == tLength) {
// 			if(right - left < minWindow) {
// 				minWindow = right - left;
// 				result = s.substr(left, right + 1);
// 			}
// 			mapping[s[left]] = -1;
// 			num--;
// 			int tmp = INT_MAX;
// 			for(int j = 0; j < tLength; j++) {
// 				if(mapping[t[j]] > left)
// 					tmp = min(tmp, mapping[t[j]]);
// 			}
// 			left = tmp;
// 		}
// 	}
// 	return result;
// }

//这一题是参照http://www.cnblogs.com/Azhu/p/4127606.html
//总感觉别人做题目时，能有一种化繁为简的能力，能将特别复杂的逻辑简化，然后用很简单的代码表示出来，而
//自己去写代码时，则不能将逻辑简化，只是一味的将复杂的逻辑用代码写出来，然后就像上面的代码一样，特别复杂
string minWindow(string s, string t) {
	if(s.empty() || t.empty())
		return "";
	int count = t.size();
	int require[128] = {0};
	bool chSet[128] = {false};
	for(int i = 0; i < count; i++) {
		require[t[i]]++;
		chSet[t[i]] = true;
	}
	int i = -1;
	int j = 0;
	int minLen = INT_MAX;
	int minIdx = 0;
	while(i < (int)s.size() && j < (int)s.size()) {
		if(count > 0) {
			i++;
			require[s[i]]--;
			if(chSet[s[i]] && require[s[i]] >= 0)
				count--;
		} else {
			if(minLen > i - j + 1) {
				minLen = i - j + 1;
				minIdx = j;
			}
			require[s[j]]++;
			if(chSet[s[j]] && require[s[j]] > 0)
				count++;
			j++;
		}
	}
	if(minLen == INT_MAX)
		return "";
	return s.substr(minIdx, minLen);
}


int main() {
	string s = "ADOBECODEBANC";
	string t = "ABC";
	string result = minWindow(s, t);
	cout<<result<<endl;
	return 0;
}


