
//Subsets II 

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &nums)
{
	vector<vector<int> > results;
	int length = nums.size();
	if(length == 0)
		return results;
	sort(nums.begin(), nums.end());
	vector<int> tmpVec;
	results.push_back(tmpVec);
	int tmpNum = INT_MIN;
	vector<vector<int> > tmpRes;
	for(int i = 0; i < length; i++) {
		int resultNum;
		if(tmpNum != nums[i]) {
			resultNum = results.size();
			for(vector<vector<int> >::iterator it = tmpRes.begin(); it != tmpRes.end();)
				it = tmpRes.erase(it);
			for(int j = 0; j < resultNum; j++) {
				tmpVec = results[j];
				tmpVec.push_back(nums[i]);
				sort(tmpVec.begin(), tmpVec.end());
				tmpRes.push_back(tmpVec);
			}
			for(int k = 0; k < tmpRes.size(); k++)
				results.push_back(tmpRes[k]);
		}
		else {
			resultNum = tmpRes.size();
			vector<vector<int> > temp;
			for(vector<vector<int> >::iterator it = tmpRes.begin(); it != tmpRes.end(); it++)
				temp.push_back(*it);
			for(vector<vector<int> >::iterator it = tmpRes.begin(); it != tmpRes.end();)
				it = tmpRes.erase(it);
			for(int j = 0; j < resultNum; j++) {
				tmpVec = temp[j];
				tmpVec.push_back(nums[i]);
				sort(tmpVec.begin(), tmpVec.end());
				tmpRes.push_back(tmpVec);
			}
			for(int k = 0; k < resultNum; k++)
				results.push_back(tmpRes[k]);
		}
		tmpNum = nums[i];
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
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	vector<vector<int> > results = subsetsWithDup(nums);
	printVector(results);
}
