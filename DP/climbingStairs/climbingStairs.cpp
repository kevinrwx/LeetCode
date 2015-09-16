
//Climbing Stairs


#include <iostream>

using namespace std;

int climbStairs(int n) {
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	int tmpL = 1;
	int tmpR = 2;
	for(int i = 3; i <= n; i++) {
		tmpR = tmpL + tmpR;
		tmpL = tmpR - tmpL;
	}
	return tmpR;
}

int main() {
	int n = 10;
	int result = climbStairs(n);
	cout<<"result: "<<result<<endl;
	return 0;
}