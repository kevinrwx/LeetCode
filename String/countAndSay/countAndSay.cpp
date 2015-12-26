
//Count and Say

#include <iostream>

using namespace std;

//首先这道题的题意不是特别容易理解，其实这道题主要是让我们从左向右依次统计相同数字的个数，然后再将个数和数字依次
//写入字符串，最后将这个字符串最为下一次统计的输入
//理解了题目以后，那接下来的工作就是将数字计数，然后再将结果写入下一个字符串。为了方便统计，可以先将第一个字符写
//入myChar，然后从j=1开始计数，如果str[j]与myChar相同，则count增加1、j++，否则将统计的数字写入tmp字符串，
//再重新计数字符，最后要注意一点的是，将结尾的字符写入tmp字符串，这一点很重要！！！
string countAndSay(int n) {
	string str = "1";
	char ch[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	if(n <= 1)
		return str;
	for(int i = 2; i <= n; i++) {
		string tmp;
		int j = 1;
		int length = str.length();
		int count = 1;
		char myChar = str[0];
		while(j < length) {
			if(myChar == str[j]) {
				count++;
				j++;
			} else {
				tmp.push_back(ch[count]);
				tmp.push_back(myChar);
				myChar = str[j];
				count = 1;
				j++;
			}
		}
		if(j == length) {
			tmp.push_back(ch[count]);
			tmp.push_back(myChar);
		}
		str = tmp;
	}
	return str;
}

int main() {
	int n = 7;
	string result = countAndSay(n);
	cout<<result<<endl;
	return 0;
}