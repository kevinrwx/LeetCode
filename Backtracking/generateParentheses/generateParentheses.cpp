
//Generate Parentheses 

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void generate(vector<string> &results, string tmp, stack<char> st, string bracket, int k)
{
	if(st.empty() && k == 0) {
		results.push_back(tmp);
		tmp.clear();
	}
	else {
		for(int i = 0; i < bracket.length(); i++) {
			if(bracket[i] == bracket[0]) {
				st.push(bracket[i]);
				generate(results, tmp, st, bracket, k-1);
				st.pop();
			}
			else {
				if(!st.empty()) {
					tmp.push_back(bracket[i]);
					char temp = st.top();
					tmp.push_back(temp);
					st.pop();
					generate(results, tmp, st, bracket, k-1);
					st.push(temp);
				}
			}
		}
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> results;
	if(n == 0)
		return results;
	stack<char> st;
	string tmp;
	string bracket = "()";
	int k = 2 * n;
	generate(results, tmp, st, bracket, k);
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
	int n = 1;
	results = generateParenthesis(n);
	printVector(results);
	return 0;
}