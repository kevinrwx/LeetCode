
//Excel Sheet Column Number

#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

//int titleToNumber(string s)
//{
//    if(s.size() == 0)
//        return 0;
//    int num = 0;
//    map<string, int> mapping;
//    mapping["A"] = 1;
//    mapping["B"] = 2;
//    mapping["C"] = 3;
//    mapping["D"] = 4;
//    mapping["E"] = 5;
//    mapping["F"] = 6;
//    mapping["G"] = 7;
//    mapping["H"] = 8;
//    mapping["I"] = 9;
//    mapping["J"] = 10;
//    mapping["K"] = 11;
//    mapping["L"] = 12;
//    mapping["M"] = 13;
//    mapping["N"] = 14;
//    mapping["O"] = 15;
//    mapping["P"] = 16;
//    mapping["Q"] = 17;
//    mapping["R"] = 18;
//    mapping["S"] = 19;
//    mapping["T"] = 20;
//    mapping["U"] = 21;
//    mapping["V"] = 22;
//    mapping["W"] = 23;
//    mapping["X"] = 24;
//    mapping["Y"] = 25;
//    mapping["Z"] = 26;
//
//    for(string::size_type ix = 0; ix != s.size(); ix++) {
//        num = num * 26 + mapping[s[ix]];
//    }
//    return num;
//
//}


int main()
{
    string str = "AAAAA";
//    cout<<str<<": "<<titleToNumber(str)<<endl;
    map<string, int> myMap;
    myMap["A"] = 2;
    string::size_type i = 3;
    string s = &str[i];
    cout<<str[i]<<endl;
    if(myMap.find("A") != myMap.end())
        cout<<myMap["A"]<<endl;
    return 0;
}
