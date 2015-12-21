

//Divide Two Integers

#include <iostream>

using namespace std;

unsigned long opposite(int num) {
    return ~num + 1;
}

//这种方法是比较传统的方法，很容易想到，而且比较简单，但是对于被除数很大，除数很小的情况，运算时间比较长
//所以最后提交的时候会超时
// int divide(int dividend, int divisor) {
// 	if(divisor == 0)
// 		return INT_MAX;
// 	int result = 0;
// 	int flag;
// 	if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
// 		flag = -1;
// 	else
// 		flag = 1;
// 	if(dividend < 0) {
// 		dividend = opposite(dividend);
// 	}
// 	if(divisor < 0) {
// 		divisor = opposite(divisor);
// 	}
// 	while(dividend >= divisor) {
// 		dividend -= divisor;
// 		result++;
// 	}
// 	if(flag < 0)
// 		result = opposite(result);
// 	return result;
// }

//对这种题目真是特别头疼，主要是INT_MAX和INT_MIN，对于这种会越界的情况，还需要再多加强练习
long long divide(int dividend, int divisor) {
	if(divisor == 0 || dividend == 0)
		return 0;
	long long lDividend = dividend;
	long long lDivisor = divisor;
	int flag = 1;
	long long digit = 0;
	long long result = 0;
	if((lDividend < 0 && lDivisor > 0) || (lDividend > 0 && lDivisor < 0))
		flag = -1;
	if(lDividend == INT_MIN) {
		result = 1;
		lDividend += abs(lDivisor);
	}
	if(lDivisor == INT_MIN)
		return result;
	if(lDividend < 0)
		lDividend = opposite(lDividend);
	if(lDivisor < 0)
		lDivisor = opposite(lDivisor);
	while(lDivisor <= (lDividend>>1)) {
		lDivisor <<= 1;
		digit++;
	}
	while(digit >= 0) {
		if(lDividend >= lDivisor) {
			lDividend -= lDivisor;
			result += 1<<digit;
		}
		lDivisor >>= 1;
		digit--;
	}
	if(flag < 0)
		result = opposite(result);
	if(result >= INT_MAX)
		result = INT_MAX;
	return result;
}

int main() {
	int dividend = -2147483648;
	int divisor = -1;
	int result = divide(dividend, divisor);
	cout<<result<<endl;
	return 0;
}


