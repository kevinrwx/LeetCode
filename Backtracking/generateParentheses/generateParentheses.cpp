
//Generate Parentheses

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//参考：http://blog.csdn.net/u011095253/article/details/9158429
void generate(vector<string> &results, string tmp, int left, int right)
{
	if(left == 0 && right == 0) {
		results.push_back(tmp);
	}
	if(left > 0) {
		tmp.push_back('(');
		generate(results, tmp, left-1, right);
		tmp = tmp.substr(0, tmp.length() - 1);
	}
	if(left < right) {
		tmp.push_back(')');
		generate(results, tmp, left, right - 1);
		tmp = tmp.substr(0, tmp.length() - 1);
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> results;
	if(n <= 0)
		return results;
	string tmp;
	generate(results, tmp, n, n);
	return results;
}

void printVector(vector<string> &results)
{
	int len = results.size();
	if(len == 0)
		cout<<"empty results"<<endl;
	for(int i = 0; i < len; i++)
		cout<<results[i]<<endl;
}

int main()
{
	vector<string> results;
	int n = 3;
	results = generateParenthesis(n);
	printVector(results);
	return 0;
}
