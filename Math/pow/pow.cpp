
//pow

#include <iostream>

using namespace std;

//计算n为正值时x的n次幂，采用倍增的计算方法，计算复杂度为O(logn)
double positiveN(double x, int n) {
	double result = 1;
	double tmp = x;
	while(n != 0) {
		if(n % 2 != 0)
			result *= tmp;
		tmp *= tmp;
		n /= 2;
	}
	return result;
}

double myPow(double x, int n) {
	double result;
	if(n >= 0) {
		result = positiveN(x, n);
	} else {
		result = 1/positiveN(x, -n);
	}
	return result;
}

int main() {
	double x = 34.00515;
	int n = -3;
	double result = myPow(x, n);
	cout<<result<<endl;
	return 0;
}