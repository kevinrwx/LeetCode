
//Add Binary

#include <iostream>
#include <stack>

using namespace std;

////�����������뷨����תΪ���֣�����Ժ���תΪ�ַ������������ύ�����ʱ��
////ȴ�����������ֵĴ�С��������������������Ҫֱ�Ӷ��ַ������в�����
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
    int length = lengthA <= lengthB ? lengthA : lengthB;
}


int main()
{
    string stra = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    string strb = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    string result = addBinary(stra, strb);
//    string str = "0";
//    int n = 0;
//    string result = intToStr(n);
    cout<<"The Result is: "<<result<<endl;
    return 0;
}