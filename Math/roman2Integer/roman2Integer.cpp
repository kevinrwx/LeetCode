
//Roman to Integer

#include <iostream>

using namespace std;

int getRomanValue(char c) {
	switch(c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
	}
}

//从后往前进行遍历，如果i位置的字符大于或等于i+1位置的字符，那就加上i位置字符的值，否则就减去i位置上的字符
int romanToInt(string s) {
	int length = s.length();
	int result = 0;
	if(length < 1)
		return result;
	result += getRomanValue(s.at(length-1));
	for(int i = length - 2; i >= 0; i--) {
		int front = getRomanValue(s.at(i));
		int end = getRomanValue(s.at(i+1));
		if(front >= end)
			result += front;
		else
			result -= front;
	}
	return result;
}

int main() {
	string str = "MMMCMXCIX";
	int result = romanToInt(str);
	cout<<result<<endl;
	return 0;
}