
//Repeated DNA Sequences

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
	int length = s.length();
	vector<string> result;
	if(length < 10)
		return result;
	unordered_map<string, int> mapping;
	for(int i = 0; i <= length - 10; i++) {
		string tmp = s.substr(i, 10);
		if(mapping.find(tmp) != mapping.end()) {
			if(mapping[tmp] == 1)
				result.push_back(tmp);
			mapping[tmp]++;
		} else {
			mapping[tmp] = 1;
		}
	}
	return result;
}

void printVector(vector<string>& result) {
	int length = result.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++)
		cout<<result[i]<<" ";
	cout<<endl;
}

int main() {
	// string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	string s = "AAAAAAAAAAAA";
	vector<string> result = findRepeatedDnaSequences(s);
	printVector(result);
	return 0;
}