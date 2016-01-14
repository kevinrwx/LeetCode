
//Factorial Trailing Zeroes

#include <iostream>

using namespace std;

//这道题其实就是组合数学的一道题目，由于结尾为0，所以只要统计2和5的个数就可以了，有由于2的个数要多于5的个数,
//所以这道题目就变成计算从1到n相乘中5的个数
//在统计5的个数时也用到了组合数学的公式，N = a[1] + (2*a[2] - a[2]) + (3 * a[3] - 2*a[2]) +...+(n*a[n] - (n-1)*a[n-1]) = a[1] + a[2] +..+ a[n]
//其中a[n]等于num/pow(5, n)
int trailingZeroes(int num) {
	int fiveCounts = 0;
	long long power = 1;
	while(power <= num) {
		power *= 5;
		fiveCounts += (num/power);
	}
	return fiveCounts;
}

int main() {
	// int n = 1808548329;
	int n = 2147483647;
	int result = trailingZeroes(n);
	cout<<result<<endl;
	return 0;
}