
//Divide Two Integers

#include <iostream>
#include <limits.h>


using namespace std;

//int divide(int dividend, int divisor)
//{
//    if(divisor == 0)
//        return INT_MAX;
//    if(dividend == 0)
//        return 0;
//    int counts = 0;
//    if(dividend > 0 && divisor > 0) {
//        while(dividend >= 0) {
//            dividend -= divisor;
//            counts++;
//        }
//    }
//    else if(dividend < 0 && divisor < 0) {
//        while(dividend <= 0) {
//            dividend -= divisor;
//            counts++;
//        }
//    }
//    else if(dividend > 0 && divisor < 0) {
//        while(dividend >= 0) {
//            dividend += divisor;
//            counts--;
//        }
//    }
//    else {
//        while(dividend <= 0) {
//            dividend += divisor;
//            counts--;
//        }
//    }
//    return (counts > 0) ? --counts : ++counts;
//}

unsigned long opposite(int num)
{
    return ~num + 1;
}

unsigned long abs(int num)
{
    if(num < 0)
        return ~(--num);
    return num;
}

//int abs(int i)
//{
//    return ((i >> 31) ^ i) - (i >> 31);
//}


unsigned long divide(int dividend, int divisor)
{
    if(divisor == 0)
        return INT_MAX;

    int tmpDividend = abs(dividend);
    int tmpDivisor = abs(divisor);

    int result = 0;
    int counts = 1;
    int sum = tmpDivisor;
    int tmpSum = 0;
    int tmpCounts = 0;

    if(sum > tmpDividend)
        return 0;
    if(sum == tmpDividend)
        return 1;
    while(tmpDividend - sum > 0) {
        tmpSum = sum;
        sum += sum;
        tmpCounts = counts;
        counts += counts;
    }
    int tmp = divide(tmpDividend - tmpSum, tmpDivisor);
    result = tmpCounts + tmp;

    if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
        return result;
    }
    else {
        return opposite(result);
    }
}


int main()
{
    int dividend = INT_MIN;
    int divisor = 1;
    unsigned long result = divide(dividend, divisor);
    cout<<"The result is: "<<result<<endl;
    return 0;
}
