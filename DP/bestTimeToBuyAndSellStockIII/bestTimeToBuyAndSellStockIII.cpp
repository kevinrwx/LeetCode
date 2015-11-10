
//Best Time to Buy and Sell Stock III

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& results) {
	int length = results.size();
	if(length == 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++) {
		cout<<results[i]<<" ";
	}
	cout<<endl;
}

//由于最多只能进行两次交易，所以可以把所有的交易日前分为两段，假设交易一发生在i日前，交易二发生在i日后，所以问题变成了两个Best Time to Buy and Sell Stock I，最后统计不同的i的情况下，各个结果的最大值便可
int maxProfit(vector<int>& prices) {
	int length = prices.size();
	int result = 0;
	if(length == 0)
		return result;
	vector<int> forwardResults(length, 0);
	vector<int> backwardResults(length, 0);
	int minimum = prices[0];
	//正向遍历，forwardResults[i]代表了prices[0...i]的最大利润
	for(int i = 1; i < length; i++) {
		int tmp = max(forwardResults[i-1], prices[i] - minimum);
		forwardResults[i] = tmp;
		minimum = min(minimum, prices[i]);
	}
	//反向遍历，backwardResults[i]代表了prices[i...n-1]的最大利润
	int maximum = prices[length-1];
	for(int j = length-2; j >= 0; j--) {
		int tmp = max(backwardResults[j+1], maximum - prices[j]);
		backwardResults[j] = tmp;
		maximum = max(maximum, prices[j]);
	}
	for(int k = 0; k < length; k++) {
		result = max(result, forwardResults[k] + backwardResults[k]);
	}
	return result;
}

int main() {
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(3);
	prices.push_back(4);
	prices.push_back(5);
	int result = maxProfit(prices);
	cout<<"result: "<<result<<endl;
	return 0;
}