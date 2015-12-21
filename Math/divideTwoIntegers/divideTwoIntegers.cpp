

//Divide Two Integers

// #include <iostream>
// #include <limits.h>


// using namespace std;

// unsigned long opposite(int num)
// {
//     return ~num + 1;
// }

// unsigned long myAbs(int num)
// {
//     if(num < 0)
//         return ~(--num);
//     return num;
// }


// int divide(int dividend, int divisor)
// {
//     if(divisor == 0)
//         return INT_MAX;
//     if(dividend == 0)
//         return 0;
//     unsigned long tmpDividend = myAbs(dividend);
//     unsigned long tmpDivisor = myAbs(divisor);

//     unsigned long result = 0;
//     unsigned long counts = 1;
//     unsigned long sum = tmpDivisor;
//     unsigned long tmpSum = 0;
//     unsigned long tmpCounts = 0;

//     if(sum > tmpDividend)
//         return 0;
//     if(sum == tmpDividend)
//         return 1;
//     while(tmpDividend > sum) {
//         tmpSum = sum;
//         sum += sum;
//         tmpCounts = counts;
//         counts += counts;
//     }
//     int tmp = divide(tmpDividend - tmpSum, tmpDivisor);
//     result = tmpCounts + tmp;

//     if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
//         if(result > INT_MAX)
//             return INT_MAX;
//         else
//             return result;
//     }
//     else {
//         if(result > INT_MAX)
//             return INT_MIN;
//         else
//             return opposite(result);
//     }
// }


// int main()
// {
//     int dividend = -214748364;
//     int divisor = 1;
//     unsigned long result = divide(dividend, divisor);

// //-2147483648
// //-1010369383
// //    int num = INT_MIN;
// //    unsigned long result = abs(num);
//     cout<<"The result is: "<<result<<endl;
//     return 0;
// }


#include <iostream>

using namespace std;

unsigned long opposite(int num) {
    return ~num + 1;
}

unsigned long myAbs(int num) {
    if(num < 0)
        return ~(--num);
    return num;
}

int divide(int dividend, int divisor) {
	int result = 0;
	int dividendSymbol = 1;
	int divisorSymbol = 1;
	if(dividend < 0) {
		dividend = opposite(dividend);
		dividendSymbol = -1;
	}
	if(divisor < 0) {
		divisor = opposite(divisor);
		divisorSymbol = -1;
	}
	while(dividend >= divisor) {
		dividend -= divisor;
		result++;
	}
	if((dividendSymbol < 0 && divisorSymbol > 0) || (dividendSymbol > 0 && divisorSymbol < 0))
		result = opposite(result);
	return result;
}

int main() {
	int dividend = 2147483647;
	int divisor = 1;
	int result = divide(dividend, divisor);
	cout<<result<<endl;
	return 0;
}






















