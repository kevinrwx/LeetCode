
//Add Binary

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

////这道题最初的想法是先转为数字，相加以后再转为字符串，但是在提交代码的时候，
////却发现现在数字的大小根本不能满足需求，所以要直接对字符串进行操作。
//long long strToInt(string str)
//{
//    int length = str.length();
//    if(length == 0)
//        return 0;
//    long long result = 0;
//    for(int i = 0; i < length; i++) {
//        if(str[i] == '1') {
//            result = 2*result + 1;
//        }
//        else {
//            result = 2*result;
//        }
//    }
//    return result;
//}
//
//string intToStr(long long n)
//{
//    if(n == 0)
//        return "0";
//    stack<int> st;
//    string result;
//    while(n != 0) {
//        st.push(n % 2);
//        n = n / 2;
//    }
//    while(!st.empty()) {
//        if(st.top() == 1)
//            result.append("1");
//        else
//            result.append("0");
//        st.pop();
//    }
//    return result;
//}
//
//string addBinary(string a, string b)
//{
//    long long va = strToInt(a);
//    long long vb = strToInt(b);
//    string result;
//    result = intToStr(va + vb);
//    return result;
//}

string addBinary(string a, string b)
{
    int lengthA = a.size();
    int lengthB = b.size();
    int length = abs(lengthA - lengthB);
    string tmp(length, '0');
    string result;
    int flag = 0;
    if(lengthA > lengthB) {
        b = tmp + b;
        result.resize(lengthA, '0');
    }
    else {
        a = tmp + a;
        result.resize(lengthB, '0');
    }
    for(int j = result.size()-1; j >= 0; j--) {
        int current = (a[j] - '0') ^ (b[j] - '0') ^ flag;
        if((a[j] - '0') + (b[j] - '0') + flag > 1)
            flag = 1;
        else
            flag = 0;
        result[j] = current + '0';
    }
    if(flag == 1)
        result = '1' + result;

    return result;
}


int main()
{
    string stra = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    string strb = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
//    string stra = "111";
//    string strb = "1";
    string result = addBinary(stra, strb);
//    string str = "0";
//    int n = 0;
//    string result = intToStr(n);
    cout<<"The Result is: "<<result<<endl;
    return 0;
}
