
//Subsets

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > subsets(vector<int> &nums)
{
	int length = nums.size();
	vector<vector<int> > results;
	if(length == 0)
		return results;
	vector<int> tmp;
	results.push_back(tmp);
	for(int i = 0; i < length; i++) {
		int resNum = results.size();
		vector<vector<int> > tmpRes;
		for(int j = 0; j < resNum; j++) {
			tmp = results[j];
			tmp.push_back(nums[i]);
			sort(tmp.begin(), tmp.end()); //由于leetcode最后要求每一条结果都是从低到高排序，所以就加了这么一句
			tmpRes.push_back(tmp);
		}
		for(int k = 0; k < resNum; k++) {
			results.push_back(tmpRes[k]);
		}
	}
	return results;
}

void printVector(vector<vector<int> > &nums)
{
	int length = nums.size();
	if(length == 0)
		cout<<"Empty Vector"<<endl;
	for(int i = 0; i < length; i++) {
		int vecLength = nums[i].size();
		for(int j = 0; j < vecLength; j++)
			cout<<nums[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(0);
	vector<vector<int> > results = subsets(nums);
	printVector(results);
}
