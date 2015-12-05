
//plus one

#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

vector<int> plusOne(vector<int>& digits) {
	int length = digits.size();
	vector<int> result;
	if(length <= 0) {
		return result;
	}
	int tmp = 1;
	for(int i = length - 1; i >= 0; i--) {
		result.push_back((digits[i] + tmp) % 10);
		tmp = (digits[i] + tmp) / 10;
	}
	if(tmp != 0) {
		result.push_back(tmp);
	}
	int n = result.size();
	for(int i = 0; i < n/2; i++) {
		swap(&result[i], &result[n-1-i]);
	}
	return result;
}

void printVector(vector<int>& nums) {
	int length = nums.size();
	if(length <= 0) {
		cout<<"empty vector";
	}
	for(int i = 0; i < length; i++) {
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}

int main() {
	vector<int> digits;
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(9);
	vector<int> result = plusOne(digits);
	printVector(result);
	return 0;

}