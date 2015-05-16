
//ZigZag Conversion

#include <iostream>
#include <string.h>

using namespace std;

string convert(string s, int numRows)
{
    int len = s.length();
    if(len == 0)
        return NULL;
    int k = numRows * 2 - 2;
    int cycle = len / k;
    int left = len % k;

    string result;
    for(int i = 1; i <= numRows; i++) {
        if(i == 1 || i == numRows) {
            for(int j = i; j < len; j += k) {
                result += s[j];
            }
        }
        else {
            for(int l = i; l < len; )
        }
    }
}

int main()
{
    string str = "PAYPALISHIRING";
    int numRows = 3;
    string result = convert(str, numRows);
    cout<<"The result is: "<<result;
    return 0;
}
