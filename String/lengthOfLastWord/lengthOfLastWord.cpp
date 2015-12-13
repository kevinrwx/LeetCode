
//Length of Last Word

#include <iostream>

using namespace std;

int lengthOfLastWord(string s) {
	int length = s.length();
	int result = 0;
	int index = 0;
	string space = " ";
	if(length <= 0)
		return result;
	//在计算最后一个单词之前，要先去掉字符串尾部的空格
	int trimIndex = 0;
	for(int i = length - 1; i >= 0; i--) {
		if(s[i] != space[0]) {
			trimIndex = i;
			break;
		}
	}
	string afterTrim = s.substr(0, trimIndex+1);
	for(int i = afterTrim.length() - 1; i >= 0; i--) {
		if(afterTrim[i] != space[0]) {
			index++;
		}
		if(afterTrim[i] == space[0] || i == 0) {
			result = index;
			break;
		}
	}
	return result;
}

int main() {
	string s = "   ";
	int result = lengthOfLastWord(s);
	cout<<result<<endl;
	return 0;
}