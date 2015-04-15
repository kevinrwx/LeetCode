
//Excel Sheet Column Number

#include <iostream>
#include <map>
#include <string>
#include <cctype>


using namespace std;

int titleToNumber(string s)
{
    int num = 0;
    int tmp;
    if(s.size() == 0)
        return 0;
    for(string::size_type ix = 0; ix != s.size(); ix++) {
        tmp = s[ix] - 'A' + 1;
        num = num * 26 + tmp;
    }
    return num;

}


int main()
{
    string str = "AA";
    cout<<"title to number: "<<titleToNumber(str)<<endl;
    return 0;
}
