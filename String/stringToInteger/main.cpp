
//String to Integer

#include <iostream>

using namespace std;

int myAtoi(string str)
{
    if(str.size() == 0)
        return 0;
    long long res;               //最后结果
    int sign = 1;          //记录正负号
    long long int_part = 0;      //整数部分
    size_t len = str.size();
    size_t i = 0;

    while(isspace(str[i]) && i < len)
        i++;

    if(i == len)
        return 0;

    if(str[i] == '-') {
        sign = -1;
        i++;
    } else if(str[i] == '+') {
        sign = 1;
        i++;
    } else if(!(str[i] >= '0' && str[i] <= '9')) {
        return 0;
    } else {
        //doing nothing
    }

    if(!(str[i] >= '0' && str[i] <= '9'))
        return 0;

    for(; i < len; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            int_part = int_part * 10 + str[i] - '0';
            if(sign == 1 && int_part > INT_MAX)
                return INT_MAX;
            if(sign == -1 && -int_part < INT_MIN)
                return INT_MIN;
        } else {
            break;
        }

    }
    res = int_part * sign;
    return res;
}


int main()
{
    string str = "  1231111111111111111111111111111111";
    cout << "The number of str is: " <<myAtoi(str)<<endl;
    return 0;
}



//double myDoubleAtoi(string str)
//{
//    if(str.size() == 0)
//        return 0;
//    int res;               //最后结果
//    int sign = 1;          //记录正负号
//    int int_part = 0;      //整数部分
//    double point_part = 0; //小数部分
//    double base = 0.1;     //用于记录小数点位数
//    size_t len = str.size();
//    size_t i = 0;
//
//    while(isspace(str[i]) && i < len)
//        i++;
//
//    if(str[i] == '-') {
//        sign = -1;
//        i++;
//    }
//
//    while(str[i] >= '0' && str[i] <= '9' && str[i] != '.' && i < len) {
//        int_part = int_part * 10 + str[i] - '0';
//        i++;
//    }
//
//    if(str[i] == '.') {
//        i++;
//    }
//    while(str[i] >= '0' && str[i] <= '9' && i != len) {
//        point_part = point_part + (str[i] - '0') * base;
//        base *= 0.1;
//    }
//    res = (int_part + point_part) * sign;
//    return res;
//
//}


















