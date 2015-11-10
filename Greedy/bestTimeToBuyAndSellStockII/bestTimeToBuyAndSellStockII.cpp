

//Best Time to Buy and Sell Stock II
#include <iostream>
#include <vector>

using namespace std;

//一直不太理解这道题目的意思，只能参考答案进行解答了
int maxProfit(vector<int>& prices) {
	int length = prices.size();
	int result = 0;
	if(length == 0)
		return result;
	for(int i = 1; i < length; i++) {
		if(prices[i] > prices[i-1])
			result += prices[i] - prices[i-1];
	}
	return result;
}

int main() {
	vector<int> prices;
	prices.push_back(2);
	prices.push_back(1);
	// prices.push_back(3);
	// prices.push_back(4);
	int result = maxProfit(prices);
	cout<<"result: "<<result<<endl;
	return 0;
}








