
//Pascal's Triangle II

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& nums) {
	int length = nums.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++)
		cout<<nums[i]<<" ";
	cout<<endl;
}

vector<int> getRow(int rowIndex) {
	if(rowIndex < 0) {
		vector<int> res;
		return res;
	}
	vector<int> result(rowIndex+1, 0);
	if(rowIndex == 0)
		return vector<int>(1, 1);
	for(int i = 1; i <= rowIndex; i++) {
		vector<int> tmp(i+1, 1);
		for(int j = 1; j < i; j++)
			tmp[j] = result[j-1] + result[j];
		for(int k = 0; k < i+1; k++)
			result[k] = tmp[k];
	}
	return result;
}

int main() {
	int rowIndex = 4;
	vector<int> result = getRow(rowIndex);
	printVector(result);
	return 0;
}