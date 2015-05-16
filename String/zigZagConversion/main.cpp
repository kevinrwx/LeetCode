
//ZigZag Conversion

#include <iostream>
#include <string.h>

using namespace std;

string convert(string s, int numRows)
{
    string result;
    int len = s.length();
    if(len == 0)
        return result;
    if(numRows == 1)
        return s;
    int k = numRows * 2 - 2;

    for(int i = 0; i < numRows; i++) {
        if(i == 0 || i == numRows-1) {
            for(int j = i; j < len; j += k) {
                result += s[j];
            }
        }
        else {
            int tmp = -i;
            for(int l = i; l < len; l += k) {
                result += s[l];
                tmp += k;
                if(tmp < len)
                    result += s[tmp];
            }
        }
    }
    return result;
}

int main()
{
//    string str = "PAYPALISHIRING";
//    int numRows = 3;
    string str = "A";
    int numRows = 2;
    string result = convert(str, numRows);
    cout<<"The result is: "<<result;
    return 0;
}
