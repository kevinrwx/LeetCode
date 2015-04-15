
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
        for(string::size_type sStart = 0, sEnd = s.size()-1; sStart < sEnd; sStart++, sEnd--) {
            if(s[sStart] != s[sEnd])
                return false;
        }
    }
    else {
        for(string::size_type sStart = 0, sEnd = s.size()-1; sStart < sEnd; sStart++, sEnd--) {
            while(!isalnum(s[sStart]))
                sStart++;
            while(!isalnum(s[sEnd]))
                sEnd--;
            if(tolower(s[sStart]) != tolower(s[sEnd]))
                return false;
            if(sStart == sEnd)
                return true;
        }
    }
    return true;
}

int main()
{
//    string str = "race a car";
    string str = "a.";
//    string str = "A man, a plan, a canal: Panama";
    if(isPalindrome(str))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
