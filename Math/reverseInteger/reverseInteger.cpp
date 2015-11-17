
//Reverse Integer

#include <iostream>
#include <limits.h>

using namespace std;

int reverse(int x) {
	int flag;
	if(x >= 0)
		flag = 1;
	else 
		flag = -1;
	x = x * flag;
	long long result = 0;
	int tmp;
	while(x > 0) {
		tmp = x % 10;
		x = x / 10;
		result = result * 10 + tmp;
		if(result > INT_MAX) {
			result = 0;
			break;
		}
	}
	return result * flag;
}

int main() {
	int x = 1534236469;
	long long result = reverse(x);
	cout<<"result: "<<result<<endl;
	return 0;
}