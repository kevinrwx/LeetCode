
//Palindrome Partitioning

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
	int length = s.length();
	if(length <= 0)
		return true;
	int i = 0;
	int j = length -1;
	while(i < j) {
		if(s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

void backtrack(vector<vector<string> >& result, vector<string>& tmp, string s, int k) {
	if(k == 0) {
		result.push_back(tmp);
	} else {
		for(int i = 1; i <= s.length(); i++) {
			string front = s.substr(0, i);
			if(isPalindrome(front)) {
				tmp.push_back(front);
				string end = s.substr(i, s.length() - i);
				backtrack(result, tmp, end, end.length());
				tmp.pop_back();
			}
		}
	}
}

vector<vector<string> > partition(string s) {
	vector<vector<string> > result;
	int length = s.length();
	if(length <= 0)
		return result;
	vector<string> tmp;
	backtrack(result, tmp, s, length);
	return result;
}

void printVector(vector<vector<string> >& result) {
	int length = result.size();
	if(length <= 0)
		cout<<"empty vector"<<endl;;
	for(int i = 0; i < length; i++) {
		for(int j = 0; j < result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
}

int main() {
	string str = "aab";
	vector<vector<string> > result = partition(str);
	printVector(result);
	return 0;
}