

//Restore IP Addresses 

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

bool isValid(string tmp)
{
	if(tmp.at(0) == '0')
		return tmp == "0" ? true : false;
	int temp = atoi(tmp.c_str());
	if(temp <= 255 && temp > 0)
		return true;
	else
		return false;
}

void generateIP(vector<string> &results, string s, string tmp, int count)
{
	if(count == 3 && isValid(s))
		results.push_back(tmp + s);
	else {
		for(int i = 1; i < 4 && i < s.length(); i++) {
			string sub = s.substr(0, i);
			if(isValid(sub))
				generateIP(results, s.substr(i, s.length()), tmp + sub + '.', count + 1);
		}
	}
}

vector<string> restoreIpAddresses(string s)
{
	vector<string> results;
	int len = s.length();
	if(len <= 0)
		return results;
	if(len < 4 || len > 12)
		return results;
	string tmp;
	int count = 0;
	generateIP(results, s, tmp, count);
	return results;
}

void printVector(vector<string> &results)
{
	int len = results.size();
	if(len <= 0)
		cout<<"empty vetor";
	for(int i = 0; i < len; i++)
		cout<<results[i]<<endl;
}

int main()
{
	string test = "25525511135";
	vector<string> results;
	results = restoreIpAddresses(test);
	printVector(results);
	return 0;
}

// int main()
// {
// 	string test = "1135";
// 	if(isValid(test))
// 		cout<<test;
// 	else
// 		cout<<"No"<<endl;
// 	return 0;
// }