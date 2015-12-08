
//Group Anagrams

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string> > groupAnagrams(vector<string>& strs) {
	vector<vector<string> > result;
	int length = strs.size();
	if(length <= 0) {
		return result;
	}
	unordered_map<string, vector<int> > mapping;
	vector<int> tmp;
	for(int i = 0; i < length; i++) {
		string s = strs[i];
		sort(s.begin(), s.end());
		mapping[s].push_back(i);
	}
	unordered_map<string, vector<int> >::iterator iter;
	for(iter = mapping.begin(); iter != mapping.end(); iter++) {
		vector<int> value = iter->second;
		vector<string> res;
		for(int i = 0; i < value.size(); i++) {
			res.push_back(strs[value[i]]);
		}
		sort(res.begin(), res.end());
		result.push_back(res);
	}
	return result;
}

void printVector(vector<vector<string> >& str) {
	int length = str.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++) {
		vector<string> tmp = str[i];
		for(int j = 0; j < tmp.size(); j++)
			cout<<tmp[j]<<" ";
	}
	cout<<endl;
}

int main() {
	vector<string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	vector<vector<string> > result = groupAnagrams(strs);
	printVector(result);
	return 0;
}