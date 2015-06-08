
//Sqrt(x)

#include <iostream>

using namespace std;

int mySqrt(int x)
{
    unsigned long long lo = 0;
    unsigned long long hi = x;
    unsigned long long mid;
    unsigned long long tmp;
    while(lo <= hi) {
        mid = lo + (hi - lo) / 2;
        tmp = mid * mid;
        if(tmp == x)
            return mid;
        else if(tmp < x) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    //��һ�δ������Ҫ����Ϊ���xû��������ƽ�����Ļ�����
    //��Ҫ����һ�����������������ƽ��ֵС��x��
    tmp = hi * hi;
    if(tmp > x)
        return hi - 1;
    else
        return hi;
}



int main()
{
    int x = 3;
    int result = mySqrt(x);
    cout<<"The result is: "<<result<<endl;
    return 0;
}
