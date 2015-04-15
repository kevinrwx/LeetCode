
//Valid Palindrome

#include <iostream>
#include <string>
#include <cctype>
#include <string.h>

using namespace std;

bool isPalindrome(string s)
{
    if(s.size() <= 1)
        return true;
    string::size_type i;
    for(i = 0; i != s.size(); i++) {
        if(isalnum(s[i])){
            break;
        }
    }
    if(i == s.size()) {
            return true;
//        for(int sStart = 0, sEnd = s.size()-1; sStart < sEnd; sStart++, sEnd--) {
//            if((sStart < sEnd) && s[sStart] != s[sEnd])
//                return false;
//        }
    }
    else {
        for(int sStart = 0, sEnd = s.size()-1; sStart < sEnd; sStart++, sEnd--) {
            while(!isalnum(s[sStart]))
                sStart++;
            while(!isalnum(s[sEnd]))
                sEnd--;
            if((sStart < sEnd) && tolower(s[sStart]) != tolower(s[sEnd]))
                return false;
        }
    }
    return true;
}

int main()
{
//    string str = "race a car";
//    string str = "a.";
    string str = ".,";
//    string str = "A man, a plan, a canal: Panama";
    if(isPalindrome(str))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
