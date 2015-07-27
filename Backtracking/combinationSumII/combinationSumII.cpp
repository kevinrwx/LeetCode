
//Combiantion Sum II

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinateVector(vector<vector<int> > &results, vector<int> &tmp, vector<int> &nums, int target, int pos)
{
	if(target == 0)
		results.push_back(tmp);
	else {
		for(int i = pos; i < nums.size(); i++) {
			if(nums[i] <= target) {
				tmp.push_back(nums[i]);
				combinateVector(results, tmp, nums, target - nums[i], i+1);
				tmp.pop_back();
				while(i < nums.size() && nums[i] == nums[i+1])
					i++;
			}
		}
	}
}

vector<vector<int> > combinationSum2(vector<int> &candinates, int target)
{
	vector<vector<int> > results;
	if(candinates.size() == 0)
		return results;
	vector<int> tmp;
	int pos = 0;
	sort(candinates.begin(), candinates.end());
	combinateVector(results, tmp, candinates, target, pos);
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
	candinates.push_back(10);
	candinates.push_back(1);
	candinates.push_back(2);
	candinates.push_back(7);
	candinates.push_back(6);
	candinates.push_back(1);
	candinates.push_back(5);
	int target = 8;
	vector<vector<int> > results;
	results = combinationSum2(candinates, target);
	printVector(results);
	return 0;
}








