
//longest palindrome substring


#include <iostream>
#include <vector>

using namespace std;

//采用动态规划的方法，假设dp[i][j]表示str[i...j]是否为回文子串，则dp[i][j]由dp[i+1][j-1]和str[i] == str[j]共同决定
string longestPalindrome(string s) {
	int length = s.length();
	if(length <= 0)
		return s;
	//不能用vector声明的二维数组，否则在提交时会报超时的错误
	bool dp[length][length];
	memset(dp, 0, sizeof(dp));
	int maxLength = 1;
	int start = 0;
	//初始化dp[0][0]、dp[1][1].....dp[n-1][n-1]
	for(int i = 0; i < length; i++)
		dp[i][i] = true;
	//初始化dp[0][1]、dp[1][2]、dp[2][3].....dp[n-2][n-1]
	for(int i = 0; i < length-1; i++) {
		if(s[i] == s[i+1]) {
			dp[i][i+1] = true;
			maxLength = 2;
			start = i;
		}
	}
	for(int k = 3; k <= length; k++) {
		for(int i = 0; i < length-k+1; i++) {
			int j = i+k-1;
			if(s[i] == s[j] && dp[i+1][j-1]) {
				dp[i][j] = true;
				if(k > maxLength) {
					maxLength = k;
					start = i;
				}
			}
		}
	}
	return s.substr(start, maxLength);
}

int main() {
	string str = "forgeeksskeegfor";
	string result = longestPalindrome(str);
	cout<<result<<endl;
	return 0;
}