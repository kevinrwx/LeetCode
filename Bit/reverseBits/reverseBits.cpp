
//Reverse Bits
#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n) {
	uint32_t result = 0;
	long long bits = 1;
	while(n != 1) {
		if(n & 0x01) {
			result = result | (0x01 << 32-bits);
		}
		bits ++;
		n = n >> 1;
	}
	return result;
}

int main() {
	uint32_t n = 2147483647;
	uint32_t result = reverseBits(n);
	cout<<result<<endl;
	return 0;
}