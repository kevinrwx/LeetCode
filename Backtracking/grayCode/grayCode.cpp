
//Gray Code

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


//这题是根据格雷码的特性解决的
//n=3的格雷码为：
//  000
//  001
//  010
//  011
//  111
//  110
//  101
//  100
//可以看出左边第一位是上下对称的，对于n=2，规律也是这样的，所以我们可以根据n-1的格雷码，分别在前面加0和加1
//然后就可以得到n的格雷码了

int binaryToInt(string str) {
	int length = str.length();
	if(length <= 0)
		return 0;
	int result = 0;
	string zero = "0";
	for(int i = length - 1; i >= 0; i--) {
		result *= 2;
		result += (str[i] - zero[0]);
	}
	return result;
}

vector<string> generateGray(int n) {
	int nums = pow(2, n);
	vector<string> gray(nums, "");
	if(n == 1) {
		gray[0].append("0");
		gray[1].append("1");
		return gray;
	}
	vector<string> tmp = generateGray(n-1);
	for(int i = 0; i < tmp.size(); i++) {
		string zeroTmp = tmp[i];
		string oneTmp = tmp[i];
		gray[i] = zeroTmp.append("0");
		gray[nums - 1 - i] = oneTmp.append("1");
	}
	return gray;
}

vector<int> grayCode(int n) {
	vector<int> result;
	if(n == 0)
		return vector<int>(1, 0);
	vector<string> gray = generateGray(n);
	for(int i = 0; i < gray.size(); i++) {
		int tmp = binaryToInt(gray[i]);
		result.push_back(tmp);
	}
	return result;
}

void printVector(vector<int>& nums) {
	int length = nums.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++)
		cout<<nums[i]<<" ";
	cout<<endl;
}

int main() {
	int n = 3;
	vector<int> result = grayCode(n);
	printVector(result);
	return 0;
}