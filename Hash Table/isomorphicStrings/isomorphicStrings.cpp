
//Isomorphic Strings

#include <iostream>
#include <unordered_map>

using namespace std;

//主要思路就是把两个string的字符挨个对应，如果不能依次对应的话，那两个string就不是同构字符串
//需要注意的是要用两个map来分别存放映射的字符，不然会报错，如果只有smapping一个map的话，s=ab，t=aa就不行
bool isIsomorphic(string s, string t) {
	if(s.length() != t.length())
		return false;
	unordered_map<char, char> smapping;
	unordered_map<char, char> tmapping;
	int length = s.length();
	for(int i = 0; i < length; i++) {
		if(smapping.find(s[i]) == smapping.end()) {
			smapping[s[i]] = t[i];
		} else {
			if(smapping[s[i]] != t[i])
				return false;
		}
		if(tmapping.find(t[i]) == tmapping.end()) {
			tmapping[t[i]] = s[i];
		} else {
			if(tmapping[t[i]] != s[i])
				return false;
		}
	}
	return true;
}

int main() {
	string s = "ab";
	string t = "aa";
	bool result = isIsomorphic(s, t);
	if(result)
		cout<<"is Isomorphic"<<endl;
	else
		cout<<"not Isomorphic"<<endl;
	return 0;
}