

//Letter Combinations of a Phone Number 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateCombinations(vector<string> &results, string letters[], string tmp, string digits, int k)
{
	if(k == digits.length())
		results.push_back(tmp);
	else {
			for(int j = 0; j < letters[digits[k] - '1'].length(); j++) {
				tmp.push_back(letters[digits[k] - '1'][j]);
				generateCombinations(results, letters, tmp, digits, k+1);
				tmp = tmp.substr(0, tmp.length() - 1);
			}
	}
}

vector<string> letterCombinations(string digits)
{
	vector<string> results;
	int len = digits.length();
	string letters[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	if(len <= 0)
		return results;
	string tmp;
	int k = 0;
	generateCombinations(results, letters, tmp, digits, 0);
	return results;
}

void printVector(vector<string> &results)
{
	int len = results.size();
	if(len <= 0)
		cout<<"empty vector";
	for(int i = 0; i < len; i++)
		cout<<results[i]<<" ";
	cout<<endl;
}

int main()
{
	string digits = "23";
	vector<string> results;
	results = letterCombinations(digits);
	printVector(results);
	return 0;
}