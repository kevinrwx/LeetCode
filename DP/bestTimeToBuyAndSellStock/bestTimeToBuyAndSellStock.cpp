
//Best Time to Buy and Sell Stock

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int length = prices.size();
	if(length == 0)
		return 0;
	int result = 0;
	int minimum = prices[0];
	for(int i = 1; i < length; i++) {
		result = max(result, prices[i] - minimum);
		minimum = min(minimum, prices[i]);
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
	prices.push_back(6);
	int result = maxProfit(prices);
	cout<<"result: "<<result<<endl;
	return 0;
}

