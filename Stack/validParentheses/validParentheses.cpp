
//Valid Parentheses

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
	int length = s.length();
	bool result = true;
	if(length <= 0)
		return result;
	stack<char> st;
	for(int i = 0; i < length; i++) {
		if(s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') {
			st.push(s.at(i));		}
		else if(s.at(i) == ')' || s.at(i) == '}' || s.at(i) == ']') {
			if(st.empty())
				result = false;
			else {
				char c = st.top();
				if(s.at(i) == ')') {
					if(c != '(')
						result = false;
				} else if(s.at(i) == '}') {
					if(c != '{')
						result = false;
				} else {
					if(c != '[')
						result = false;
				}
				st.pop();
			}
		}
	}
	if(!st.empty())
		result = false;
	return result;
}

int main() {
	string str = ")";
	bool result = isValid(str);
	if(result)
		cout<<"Valid";
	else
		cout<<"Invalid";
	cout<<endl;
	return 0;
}