

//Combination Sum III

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//只是凭感觉ac的，没有仔细考虑过为什么K做先--，再++这样的操作
void combinateVector(vector<vector<int> > &results, vector<int> &tmp, int k, int n, int pos)
{
	if(n == 0 && k == 0)
		results.push_back(tmp);
	else {
		for(int i = pos; i <= 9; i++) {
			if(i <= n) {
				tmp.push_back(i);
				combinateVector(results, tmp, --k, n-i, i+1);
				tmp.pop_back();
				k++;
			}
		}
	}
}

vector<vector<int> > combinationSum3(int k, int n)
{
	vector<vector<int> > results;
	if(n == 0)
		return results;
	vector<int> tmp;
	int pos = 1;
	combinateVector(results, tmp, k, n, pos);
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
	int n = 7;
	int k = 3;
	vector<vector<int> > results;
	results = combinationSum3(k, n);
	printVector(results);
	return 0;
}