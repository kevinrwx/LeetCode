
//Palindrome Number

#include <iostream>
#include <vector>

using namespace std;

////this is a generic way, but used extra spaces.
//bool isPalindrome(int x)
//{
//    vector<int> tmp;
//    int mod;
//    if(x < 0) {
//        return false;
//    }
//    else {
//        while(x != 0) {
//            mod = x % 10;
//            tmp.push_back(mod);
//            x /= 10;
//        }
//        for(int i = 0, j = tmp.size() - 1; i < j; i++ , j--) {
//            if(tmp[i] != tmp[j])
//                return false;
//        }
//        return true;
//    }
//}
//
////This is also a generic way, but it doesn't use extra spaces.
//bool isPalindrome(int x)
//{
//    if(x < 0)
//        return false;
//    int div = 1;
//    while(x/div >= 10)
//        div *= 10;
//    while(x > 0) {
//        int l = x / div;
//        int r = x % 10;
//        if(l != r)
//            return false;
//        x = x % div / 10;
//        div /= 100;
//    }
//    return true;
//}

//This is another awesome way!!! That's really cool!!!!!
bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    int num = x;
    int rev = 0;
    int mod;
    while(x > 0) {
        mod = x % 10;
        rev = rev * 10 + mod;
        x /= 10;
    }
    if(num == rev)
        return true;
    else
        return false;
}


int main()
{
    int temp = 1234321;
    if(isPalindrome(temp)) {
        cout<<"Palindrome number"<<endl;
    }
    else {
        cout<<"Not Palindrome number"<<endl;
    }
    return 0;
}
