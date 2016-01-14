
//Fraction to Recurring Decimal

#include <iostream>
#include <unordered_map>

using namespace std;

//我现在终于知道这道题目的通过率为什么这么低了，中间要注意的点实在是太多了
//正负号、int结果溢出(所以需要将int型变量存入long long型变量里)
string fractionToDecimal(int numerator, int denominator) {
	if(numerator == 0)
		return "0";
	if(denominator == 0)
		return "";
	string result;
	char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	//如果结果为负数
	if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
		result.push_back('-');
	//注意点：要先把numerator和denominator转为long long类型，然后再取绝对值
	long long num = numerator;
	long long den = denominator;
	// num = abs(num);
	// den = abs(den);
	long long integer = num / den;
	//将整数部分的结果存入result中
	result += to_string(integer);

	long long decimal = num % den;
	//如果能够整除，则返回结果
	if(decimal == 0)
		return result;
	result.push_back('.');
	//求小数的循环节是这道题目很关键的一部分，主要思路就是模拟除法运算，然后用一个额外的map来存放
	//余数和这个余数对应的位置如果遇到余数有重复的情况，那就判断这是循环节第二次出现的位置，那么就
	//可以把括号插入循环节中了
	unordered_map<long long, int> map;
	decimal *= 10;
	while(decimal != 0) {
		if(map.find(decimal) != map.end()) {
			result.insert(result.begin() + map[decimal], '(');
			result.push_back(')');
			return result;
		}
		map[decimal] = result.length();
		integer = decimal / den;
		result.push_back(arr[integer]);
		decimal = (decimal % den) * 10;
	}
	return result;
}

int main() {
	int numerator = 7;
	int denominator = 12;
	// float result = (float)numerator / denominator;
	// cout<<result<<endl;
	string result = fractionToDecimal(numerator, denominator);
	cout<<result<<endl;
	return 0;
}