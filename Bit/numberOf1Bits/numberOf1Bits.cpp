
//Number of 1 Bits
#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
	int count = 0;
	while(n != 0) {
		if(n & 0x01)
			count++;
		n = n >> 1;
	}
	return count;
}

int main() {
	uint32_t n = 00000000000000000000000000001011;
	int result = hammingWeight(n);
	cout<<result<<endl;
	return 0;
}