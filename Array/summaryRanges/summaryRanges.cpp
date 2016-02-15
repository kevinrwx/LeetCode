
//Summary Ranges

#include <iostream>
#include <vector>

using namespace std;

vector<string> summaryRanges(vector<int>& num) {
	vector<string> result;
	int length = num.size();
	if(length == 0)
		return result;
	int i = 0;
	while(i < length) {
		int j = 1;
		while(i+j < length && num[i+j]-num[i] == j)
			j++;
		result.push_back(j <= 1 ? to_string(num[i]) : to_string(num[i]) + "->" + to_string(num[i+j-1]));
		i += j;
	}
	return result;
}

vector<int> arr2vec(int arr[], int n) {
	vector<int> result;
	for(int i = 0; i < n; i++)
		result.push_back(arr[i]);
	return result;
}

void printVec(vector<string>& result) {
	int length = result.size();
	if(length <= 0)
		cout<<"empty vector"<<endl;
	for(int i = 0; i < length; i++)
		cout<<result[i]<<endl;
}

int main() {
	int arr[] = {0, 1, 2, 4, 5, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> num = arr2vec(arr, n);
	vector<string> result = summaryRanges(num);
	printVec(result);
	return 0;
}