
//Evaluate Reverse Polish Notation

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

//这道题目的思路比较简单，就是用一个额外的栈来存储数字，然后遇到运算符时，弹出两个数字进行计算，然后再把计算结果
//存回栈里面，最后栈只剩最后一个数字了，那就是这个计算式的结果，这里面有个麻烦的地方就是要自己额外实现判断一个字
//符串是否为数字的函数，C++中没有现成的判断函数，这点有点麻烦
bool isNum(string str) {
	if(str != "0") {
		if(atoi(str.c_str()) != 0)
			return true;
		else
			return false;
	} else {
		return true;
	}
}

int evalRPN(vector<string>& tokens) {
	int length = tokens.size();
	if(length <= 0)
		return 0;
	stack<int> st;
	for(int i = 0; i < length; i++) {
		if(isNum(tokens[i])) {
			st.push(atoi(tokens[i].c_str()));
		}
		else {
			int tmp1 = st.top();
			st.pop();
			int tmp2 = st.top();
			st.pop();
			int tmp = 0;
			if(tokens[i] == "+") {
				tmp = tmp2 + tmp1;
			} else if(tokens[i] == "-") {
				tmp = tmp2 - tmp1;
			} else if(tokens[i] == "*") {
				tmp = tmp2 * tmp1;
			} else {
				tmp = tmp2 / tmp1;
			}
			st.push(tmp);
		}
	}
	return st.top();
}

vector<string> arr2vec(string strs[], int n) {
	vector<string> result;
	for(int i = 0; i < n; i++)
		result.push_back(strs[i]);
	return result;
}

int main() {
	string strs[] = {"-1","1","*","-1","+"};
	int n = sizeof(strs) / sizeof(strs[0]);
	vector<string> tokens = arr2vec(strs, n);
	int result = evalRPN(tokens);
	cout<<result<<endl;
	return 0;
}
