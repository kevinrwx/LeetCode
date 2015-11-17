
//Reverse Integer

#include <iostream>

using namespace std;

int reverse(int x) {
	int flag;
	if(x >= 0)
		flag = 1;
	else
		flag = -1;
	int result = 0;
	int tmp;
	while(x > 0) {
		tmp = x % 10;
		x = x/10;
		result = result + tmp * 10;
	}
	return result;
}

int main() {
	int x = 123;
	int result = reverse(x);
	cout<<"result: "<<result<<endl;
	return 0;
}