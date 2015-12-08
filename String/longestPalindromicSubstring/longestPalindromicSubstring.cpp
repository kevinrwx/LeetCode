
//longest palindrome substring


// #include <iostream>

// using namespace std;

// string longestPalindrome(string s) {
// 	//
// }

// int main() {
// 	//
// }

// #include <iostream>

// using namespace std;

// //采用动态规划的方法，假设dp[i][j]表示str[i...j]是否为回文子串，则dp[i][j]由dp[i+1][j-1]和str[i] == str[j]共同决定
// int longestPalindrome(string s) {
// 	int len = s.size();
// 	bool dp[len][len];
// 	memset(dp, 0, sizeof(dp));

// 	int maxLength = 1;

// 	//初始化dp[0][0]、dp[1][1].....dp[n-1][n-1]
// 	for(int i = 0; i < len; i++) {
// 		dp[i][i] = true;
// 	}
// 	//初始化dp[0][1]、dp[1][2]、dp[2][3].....dp[n-2][n-1]
// 	int start = 0;
// 	for(int i = 0; i < len-1; i++) {
// 		if(s.at(i) == s.at(i+1)) {
// 			dp[i][i+1] = true;
// 			start = i;
// 			maxLength = 2;
// 		}
// 	}

// 	for(int k = 3; k <= len; k++) {
// 		for(int i = 0; i < len-k+1; i++) {
// 			int j = i+k-1;
// 			if(s.at(i) == s.at(j) && dp[i+1][j-1]) {
// 				dp[i][j] = true;
// 				if(k > maxLength) {
// 					start = i;
// 					maxLength = k;
// 				}
// 			}
// 		}
// 	}
// 	string result = s.substr(start, maxLength);
// 	cout<<result<<endl;
// 	return maxLength;
// }

// int main() {
// 	string str = "forgeeksskeegfor";
// 	int result = longestPalindrome(str);
// 	return 0;
// }








