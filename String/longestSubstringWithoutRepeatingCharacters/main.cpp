
//Longest Substring Without Repeating Characters

#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

//第一种方法只考虑了字符为26个字母的情况
//int lengthOfLongestSubstring(string s)
//{
//    int length = s.length();
//    if(length == 0)
//        return 0;
//    int count[26];
//    memset(count, -1, sizeof(count));
//
//    int len = 0;
//    int maxV = 0;
//    for(int i = 0; i < length; i++, len++) {
//        if(count[s[i] - 'a'] >= 0) {
//            i = count[s[i] - 'a'] + 1;
//            memset(count, -1, sizeof(count));
//            maxV = max(len, maxV);
//            len = 0;
//        }
//        count[s[i] - 'a'] = i;
//    }
//    return max(len, maxV);
//}

int lengthOfLongestSubstring(string s)
{
    int length = s.length();
    if(length == 0)
        return 0;
    int count[256];
    memset(count, -1, sizeof(count));
    int len = 0;
    int maxV = 0;
    for(int i = 0; i < length; i++, len++) {
        if(count[s[i] - ' '] >= 0) {
            maxV = max(len, maxV);
            i = count[s[i] - ' '] + 1;
            len = 0;
            memset(count, -1, sizeof(count));
        }
        count[s[i] - ' '] = i;
    }
    return max(len, maxV);
}


int main()
{
    string str = "abcb";
    int result = lengthOfLongestSubstring(str);
    cout<<"The result is: "<<result<<endl;
    return 0;
}





