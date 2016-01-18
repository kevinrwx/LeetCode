
//Excel Sheet Column Title
#include <iostream>
#include <stack>

using namespace std;

//这道题目的有点贱贱的，看题意像是把一个整数转换成26进制的数，但是这个题目的计数不是从0开始的
//是从1开始的，所以每次进行计算前都要把n减一
string convertToTitle(int n) {
	if(n <= 0)
		return NULL;
	stack<char> st;
	string result;
	char ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	while(n != 0) {
		n--;
		st.push(ch[n % 26]);
		n /= 26;
	}
	while(!st.empty()) {
		result.push_back(st.top());
		st.pop();
	}
	return result;
}

int main() {
	int n = 26;
	string result = convertToTitle(n);
	cout<<result<<endl;
	return 0;
}