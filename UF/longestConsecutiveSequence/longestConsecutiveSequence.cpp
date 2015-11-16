
//Longest Consecutive Sequence

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// int longestConsecutive(vector<int>& nums) {
// 	int length = nums.size();
// 	int result = 0;
// 	if(length <= 0)
// 		return result;
// 	unordered_map<int, int> hashmap;
// 	for(int i = 0; i < length; i++) {
// 		hashmap[nums[i]] = i;
// 	}
// 	vector<int> visited(length, 0);
// 	for(int i = 0; i < length; i++) {
// 		if(visited[i] == 1)
// 			continue;
// 		visited[i] = 1;
// 		int count = 1;
// 		int tmp = nums[i] - 1;
// 		while(hashmap.find(tmp) != hashmap.end()) {
// 			count++;
// 			visited[hashmap[tmp]] = 1;
// 			tmp--;
// 		}
// 		tmp = nums[i] + 1;
// 		while(hashmap.find(tmp) != hashmap.end()) {
// 			count++;
// 			visited[hashmap[tmp]] = 1;
// 			tmp++;
// 		}
// 		result = max(result, count);
// 	}
// 	return result;
// }

//上面一个函数是使用unordered_map，最后导致超时，所以现在使用unordered_set
//虽然leetcode提示可以使用union-find，但是实在没有想出来该怎么用，所以只能用
//这种方法了，希望第二遍的时候会想到union-find的方法
int longestConsecutive(vector<int>& nums) {
	int length = nums.size();
	int result = 0;
	if(length <= 0)
		return result;
	unordered_set<int> ht;
	for(int i = 0; i < nums.size(); i++) {
		ht.insert(nums[i]);
	}
	for(int i = 0; i < length; i++) {
		if(ht.empty())
			break;
		int curNum = nums[i];
		int curLen = 0;
		while(ht.count(curNum)) {
			ht.erase(curNum);
			curLen++;
			curNum++;
		}
		curNum = nums[i] - 1;
		while(ht.count(curNum)) {
			ht.erase(curNum);
			curLen++;
			curNum--;
		}
		result = max(curLen, result);
	}
	return result;
}

int main() {
	vector<int> nums;
	nums.push_back(100);
	nums.push_back(4);
	nums.push_back(200);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(5);
	int result = longestConsecutive(nums);
	cout<<"result: "<<result<<endl;
	return 0;
}