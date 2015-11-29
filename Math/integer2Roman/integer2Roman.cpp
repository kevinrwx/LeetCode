
//Integer to Roman


#include <iostream>
#include <stack>

using namespace std;
 
string intToRoman(int num) {
	string roman[4][10] = {
		{"","I","II","III","IV","V","VI","VII","VIII","IX"},
        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
        {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
        {"","M","MM","MMM"}
    };
	string result;
	if(num < 1 || num > 3999) 
		return result;
	stack<int> digits;
	int position = 0;
	while(num > 0) {
		digits.push(num % 10);
		num /= 10;
		position++;
	}
	while(!digits.empty()) {
		int tmp = digits.top();
		digits.pop();
		result.append(roman[--position][tmp]);
	}
	return result;
}

int main() {
	int num = 3999;
	string result = intToRoman(num);
	return 0;
}