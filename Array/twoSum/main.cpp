#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &num, int target)
{
    int gap;
    unordered_map<int, int> mapping;
    vector<int> result;
    for(int i = 0; i < num.size(); i++) {
        mapping[num[i]] = i;
    }
    for(int j = 0; j < num.size(); j++) {
        gap = target - num[j];
        if(mapping.find(gap) != mapping.end()) {
            cout<<j+1<<endl;
            result.push_back(j + 1);
            cout<<mapping[gap] + 1<<endl;
            result.push_back(mapping[gap] + 1);
            break;
        }
    }
}


int main()
{
    vector<int> v;
    vector<int> res;
    int target = 11;
    v.push_back(6);
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);
    v.push_back(3);
    res = twoSum(v, target);
    cout<<"result is: "<<res[0]<<", "<<res[1]<<endl;
    return 0;
}
