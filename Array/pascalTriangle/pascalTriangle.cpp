
//Pascal's Triangle

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int nRows) {
	vector<vector<int> > result;
	if(nRows == 0)
		return result;
	result.push_back(vector<int>(1, 1));
	for(int i = 1; i < nRows; i++) {
		vector<int> tmp;
		tmp.push_back(1);
		for(int j = 1; j < i; j++) {
			tmp.push_back(result[i-1][j-1] + result[i-1][j]);
		}
		tmp.push_back(1);
		result.push_back(tmp);
	}
	return result;
}

void printVector(vector<vector<int> >& nums) {
	int length = nums.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++) {
		for(int j = 0; j < nums[i].size(); j++)
			cout<<nums[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main() {
	int nRows = 4;
	vector<vector<int> > result = generate(nRows);
	printVector(result);
	return 0;
}