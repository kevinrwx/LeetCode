
//Maximum Subarray

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVector(vector<int> &nums);

//动态规划方法,还可以继续优化，不需要用temp来存储所有的中间结果，只需要一个变量就行了
//ToDo:http://blog.sina.com.cn/s/blog_6d0d2ed10100t87t.html  可以参考  还待理解
int maxSubArrayI(vector<int> &nums)
{
	int results = 0;
	int length = nums.size();
	if(length == 0)
		return 0;
	vector<int> temp;
	temp.push_back(nums[0]);
	results = nums[0];
	for(int i = 1; i < length; i++) {
		if(temp[i-1] + nums[i] > nums[i])
			temp.push_back(temp[i-1] + nums[i]);
		else
			temp.push_back(nums[i]);
		results = max(results, temp[i]);
	}
	return results;
}

//ToDo：用分治法
//可以参考:http://blog.csdn.net/superchanon/article/details/8228212(数据结构：C语言实现)
int maxSubArrayII(vector<int> &nums)
{
	//
	return 0;
}

vector<int> arrToVector(int arr[], int n)
{
	vector<int> results;
	if(n == 0)
		return results;
	for(int i = 0; i < n; i++)
		results.push_back(arr[i]);
	return results;
}

void printVector(vector<int> &nums)
{
	int length = nums.size();
	if(length == 0)
		cout<<"Empty Vector"<<endl;
	for(int i = 0; i < length; i++)
		cout<<nums[i]<<" ";
	cout<<endl;
}

int main()
{
	int arr[] = {-2, -3, -4, -1, -5};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> nums;
	nums = arrToVector(arr, n);
	printVector(nums);
	int results = maxSubArrayI(nums);
	cout<<"The Results is: "<<results<<endl;
	return 0;
}