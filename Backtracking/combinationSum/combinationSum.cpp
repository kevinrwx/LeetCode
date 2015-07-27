
//Combination Sum

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinateVector(vector<vector<int> > &results, vector<int> tmp, vector<int> &nums, int target, int start)
{
	if(target == 0)
		results.push_back(tmp);
	else {
		for(int i = start; i < nums.size(); i++) {
			if(nums[i] <= target) {
				tmp.push_back(nums[i]);
				combinateVector(results, tmp, nums, target-nums[i], i);
				tmp.pop_back();
			}
		}
	}
}

vector<vector<int> > combinationSum(vector<int> &candinates, int target)
{
	vector<vector<int> > results;
	if(candinates.size() == 0)
		return results;
	vector<int> tmp;
	sort(candinates.begin(), candinates.end());
	combinateVector(results, tmp, candinates, target, 0);
	return results;
}

void printVector(vector<vector<int> > &num)
{
    if(num.size() == 0)
        cout<<"Empty vector"<<endl;
    for(size_t i = 0; i < num.size(); i++) {
        for(size_t j = 0; j < num[i].size(); j++)
            cout<<num[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
	vector<int> candinates;
	candinates.push_back(8);
	candinates.push_back(7);
	candinates.push_back(4);
	candinates.push_back(3);
	int target = 11;
	vector<vector<int> > results;
	results = combinationSum(candinates, target);
	printVector(results);
	return 0;
}