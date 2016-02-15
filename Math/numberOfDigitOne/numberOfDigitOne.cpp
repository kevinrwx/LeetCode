
//Number of Digit One

#include <iostream>

using namespace std;

//这道题的思路就是分别计算个位、十位、百位等为1时num的个数，然后再把这些个数相加，相加后的和就是所有1的个数
//以计算十位数为1为例：假设十位上0、1和大于等于2这三种情况，m = 10
//case 1：n = 205，a = n/m = 2，b = n%m = 5，计算十位上1的个数为2*10次
//case 2：n = 215，a = n/m = 2，b = n%m = 5，计算十位上1的个数为2*10 + (5+1)次
//case 3：n = 225，a = n/m = 2，b = n%m = 5，计算十位上1的个数为(2+1)*10次
//以上三种情况可以用一个公式概括：(a + 8) / 10 * m + ((a % 10 == 1) ? 1 : 0) * (b + 1)
int countDigitOne(int n) {
	int result = 0;
	if(n <= 0)
		return 0;
	for(long m = 1; m <= n; m *= 10) {
		long a = n / m;
		long b = n % m;
		result += (a + 8) / 10 * m;
		if(a % 10 == 1)
			result += (b + 1);
	}
	return result;
}

int main() {
	int n = 214748364;
	int result = countDigitOne(n);
	cout<<result<<endl;
	return 0;
}