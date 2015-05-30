
//Divide Two Integers

#include <iostream>
#include <limits.h>


using namespace std;

unsigned long opposite(int num)
{
    return ~num + 1;
}

unsigned long myAbs(int num)
{
    if(num < 0)
        return ~(--num);
    return num;
}


int divide(int dividend, int divisor)
{
    if(divisor == 0)
        return INT_MAX;
    if(dividend == 0)
        return 0;
    unsigned long tmpDividend = myAbs(dividend);
    unsigned long tmpDivisor = myAbs(divisor);

    unsigned long result = 0;
    unsigned long counts = 1;
    unsigned long sum = tmpDivisor;
    unsigned long tmpSum = 0;
    unsigned long tmpCounts = 0;

    if(sum > tmpDividend)
        return 0;
    if(sum == tmpDividend)
        return 1;
    while(tmpDividend > sum) {
        tmpSum = sum;
        sum += sum;
        tmpCounts = counts;
        counts += counts;
    }
    int tmp = divide(tmpDividend - tmpSum, tmpDivisor);
    result = tmpCounts + tmp;

    if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
        if(result > INT_MAX)
            return INT_MAX;
        else
            return result;
    }
    else {
        if(result > INT_MAX)
            return INT_MIN;
        else
            return opposite(result);
    }
}


int main()
{
    int dividend = -2147483648;
    int divisor = 1;
    unsigned long result = divide(dividend, divisor);

//-2147483648
//-1010369383
//    int num = INT_MIN;
//    unsigned long result = abs(num);
    cout<<"The result is: "<<result<<endl;
    return 0;
}


