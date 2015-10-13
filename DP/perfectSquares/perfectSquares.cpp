
//Perfect Squares

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//改题目仍然采用DP的方式，对于每一个n，tmp=[sqrt(n)](下取整)，然后从tmp依次遍历1，取出所有结果的最小值，该值就是想要的结果
int numSquares(int n) {
	if(n == 0)
		return 0;
	vector<int> results(n+1, 0);
	for(int i = 1; i <= n; i++) {
		int tmp = (int)sqrt(i);
		int minimum = INT_MAX;
		for(int j = tmp; j > 0; j--) {
			minimum = min(minimum, results[i-j*j] + 1);
		}
		results[i] = minimum;
	}
	return results[n];
}

int main() {
	int n = 13;
	int result = numSquares(n);
	cout<<" result: "<<result<<endl;
	return 0;
}