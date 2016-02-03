
//majority element II

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//参考链接在这里，http://blog.csdn.net/labud/article/details/47056421
// vector<int> majorityElement(vector<int>& num) {
// 	vector<int> result;
// 	int length = num.size();
// 	if(length <= 0)
// 		return result;
// 	unordered_map<int, int> mapping;
// 	unordered_map<int, int>::iterator it;
// 	for(int i = 0; i < length; i++) {
// 		if(mapping.find(num[i]) == mapping.end())
// 			mapping[num[i]] = 1;
// 		else
// 			mapping[num[i]]++;
// 		if(mapping.size() > 3) {
// 			for(it = mapping.begin(); it != mapping.end(); it++) {
// 				it->second--;
// 				if(it->second == 0)
// 					mapping.erase(it);
// 			}
// 		}
// 	}
// 	for(it = mapping.begin(); it != mapping.end(); it++) {
// 		it->second = 0;
// 	}
// 	for(int i = 0; i < length; i++) {
// 		if(mapping.find(num[i]) != mapping.end())
// 			mapping[num[i]]++;
// 	}
// 	for(it = mapping.begin(); it != mapping.end(); it++) {
// 		if(it->second > length/3) {
// 			result.push_back(it->first);
// 		}
// 	}
// 	return result;
// }

vector<int> majorityElement(vector<int>& nums) {
    int length = nums.size();
    vector<int> result;
    if(length <= 0)
        return result;
    int cnt1 = 0, cnt2 = 0;
    int num1 = 0, num2 = 0;
    //在这个循环内，要注意if条件的顺序，先判断num1或者num2是否跟nums[i]相同，然后再判断
    for(int i = 0; i < length; i++) {
        if(nums[i] == num1)
            cnt1++;
        else if(nums[i] == num2) {
            cnt2++;
        } else if(cnt1 == 0) {
            num1 = nums[i];
            cnt1 = 1;
        } else if(cnt2 == 0) {
            num2 = nums[i];
            cnt2 = 1;
        } else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i = 0; i < length; i++) {
        if(nums[i] == num1)
            cnt1++;
        else if(nums[i] == num2)
            cnt2++;
    }
    if(cnt1 > length/3)
        result.push_back(num1);
    if(cnt2 > length/3)
        result.push_back(num2);
    return result;
}

vector<int> arr2vec(int arr[], int n) {
	vector<int> result;
	for(int i = 0; i < n; i++)
		result.push_back(arr[i]);
	return result;
}

void printVec(vector<int>& num) {
	int length = num.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++)
		cout<<num[i]<<" ";
	cout<<endl;
}

int main() {
	int arr[] = {8,8,7,7,7};
	// int arr[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};
	// int arr[] = {47,47,72,47,72,47,79,47,12,92,13,47,47,83,33,15,18,47,47,47,47,64,47,65,47,47,47,47,70,47,47,55,47,15,60,47,47,47,47,47,46,30,58,59,47,47,47,47,47,90,64,37,20,47,100,84,47,47,47,47,47,89,47,36,47,60,47,18,47,34,47,47,47,47,47,22,47,54,30,11,47,47,86,47,55,40,49,34,19,67,16,47,36,47,41,19,80,47,47,27};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> num = arr2vec(arr, n);
	vector<int> result = majorityElement(num);
	printVec(result);
	return 0;
}
