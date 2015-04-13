
//Valid Palindrome

#include <iostream>
#include <string.h>

using namespace std;

//bool isPalindrome(string s)
//{
//    if(s.size() == 0)
//        return false;
//    char* sStart = &s[0];
//    char* sEnd = &s[s.size()-1];
//    char c1 = " ";
//    char c2 = ",";
//    char c3 = ":";
//    char c4 = ".";
//    while(sStart <= sEnd) {
//        if(*sStart == c1 || *sStart == c2 || *sStart == c3 || *sStart == c4)
//            sStart++;
//        if(*sEnd == c1 || *sEnd == c2 || *sEnd == c3 || *sEnd == c4)
//            sEnd--;
//        if(*sStart != *sEnd)
//            return false;
//        sStart++;
//        sEnd--;
//    }
//    return true;
//}

int main()
{
//    string str = "race a car";
    string str = "A man, a plan, a canal: Panama";
//    if(isPalindrome(str))
//        cout<<"yes"<<endl;
//    else
//        cout<<"no"<<endl;
    char* s = &str[0];
    cout<<*s<<endl;
    const char* c = (const char*)"A";
    cout<<*c<<endl;
    if(strcmp(s, c) == 0)
        cout<<"the same"<<endl;
    else
        cout<<"not the same"<<endl;
    return 0;
}
