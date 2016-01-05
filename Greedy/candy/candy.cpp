
//candy

#include <iostream>
#include <vector>

using namespace std;

//这道题目的标签是Greedy，但是我对于贪心的题目现在还没有什么思路，这道题目并不是我独立想出来的
//这道题目的思路是：一、先从左往右进行扫描，如果rating[i]大于rating[i-1]，则candy[i]等于candy[i-1]+1；
//二、从左往右扫描完毕以后，再从右往左进行扫描，对于rating[i]大于rating[i+1],且candy[i]小于等于candy[i+1]
//的情况，让candy[i]等于candy[i+1]+1；三、完成从右往左的扫描以后，对candy数组进行求和，和就是最后的结果
int candy(vector<int>& ratings) {
	if(ratings.empty())
		return 0;
	int length = ratings.size();
	int count = 0;
	vector<int> candy(length, 1);
	for(int i = 1; i < length; i++) {
		if(ratings[i] > ratings[i-1])
			candy[i] = candy[i-1] + 1;
	}
	for(int i = length-2; i >= 0; i--) {
		if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1])
			candy[i] = candy[i+1] + 1;
	}
	for(int i = 0; i < length; i++)
		count += candy[i];
	return count;
}

vector<int> arr2vec(int arr[], int n) {
	vector<int> vec;
	for(int i = 0; i < n; i++)
		vec.push_back(arr[i]);
	return vec;
}

int main() {
	int arr[] = {1, 2, 4, 3, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> ratings = arr2vec(arr, n);
	int result = candy(ratings);
	cout<<result<<endl;
	return 0;
}