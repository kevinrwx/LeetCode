
//Power of Two

#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) {
	if(n <= 0)
		return false;
	return (n & (n-1)) == 0 ? true : false;
}

int main() {
	int n = 2;
	if(isPowerOfTwo(n))
		cout<<"is Power Of Two"<<endl;
	else
		cout<<"not"<<endl;
	return 0;
}