
//Divide Two Integers

#include <iostream>
#include <limits.h>

using namespace std;

int divide(int dividend, int divisor)
{
    if(divisor == 0)
        return INT_MAX;
    if(dividend == 0)
        return 0;
    int counts = 0;
    if(dividend >0 && divisor > 0) {
        while(dividend >= 0) {
            dividend -= divisor;
            counts++;
        }
    }
    else if(dividend < 0 && divisor < 0) {
        while(dividend <= 0) {
            dividend -= divisor;
            counts++;
        }
    }
    else if(dividend > 0 && divisor < 0) {
        while(dividend >= 0) {
            dividend += divisor;
            counts--;
        }
    }
    else {
        while(dividend <= 0) {
            dividend += divisor;
            counts--;
        }
    }
    return (counts > 0) ? --counts : ++counts;
}

int main()
{
    int dividend = 0;
    int divisor = 9;
    int result = divide(dividend, divisor);
    cout<<"The result is: "<<result<<endl;
    return 0;
}
