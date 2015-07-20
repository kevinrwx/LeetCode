
//Combinations

#include <iostream>
#include <vector>

using namespace std;

void permuteVector(vector<vector<int> > &results, vector<int> &num, int n, int k, int start)
{
    if(k == num.size())
        results.push_back(num);
    for(int i = start; i <= n; i++)
    {
        num.push_back(i);
        permuteVector(results, num, n, k, i+1);
        num.pop_back();
    }
}


vector<vector<int> > combine(int n, int k)
{
	vector<vector<int> > results;
	if(k > n || n == 0 || k == 0)
		return results;
	vector<int> num;
    int start = 1;
    permuteVector(results, num, n, k, start);
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
	int n = 4;
    int k = 3;
    vector<vector<int> > results = combine(n, k);
    printVector(results);
    return 0;
}