
//permutationsII

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permuteVector(vector<vector<int> > &results, vector<int> &tmp, vector<int> &nums, bool visited[])
{
	if(tmp.size() == nums.size())
		results.push_back(tmp);
	else {
		for(int i = 0; i < nums.size(); i++) {
			if(visited[i] == false) {
				tmp.push_back(nums[i]);
				visited[i] = true;
				permuteVector(results, tmp, nums, visited);
				tmp.pop_back();
				visited[i] = false;
				while(i < nums.size()-1 && nums[i] == nums[i+1])
					i++;
			}
		}
	}
}

vector<vector<int> > permuteUnique(vector<int> &nums)
{
	int len = nums.size();
	vector<vector<int> > results;
	if(len == 0)
		return results;
	bool *visited = new bool[len];
	memset(visited, 0, sizeof(bool) * len);
	vector<int> tmp;
	sort(nums.begin(), nums.end());
	permuteVector(results, tmp, nums, visited);
	delete[] visited;
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
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);

	vector<vector<int> > results;
	results = permuteUnique(nums);
	printVector(results);
	return 0;
}
