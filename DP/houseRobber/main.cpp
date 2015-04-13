
//House Robber

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int rob(vector<int> &num)
{
    if(num.size() == 0)
        return 0;
    int n = num.size();
    int value[n];
    value[0] = num[0];
    value[1] = max(num[0], num[1]);

    for(vector<int>::size_type i = 2; i < num.size(); i++) {
        if(value[i-1] == value[i-2]) {
            value[i] = value[i-1] + num[i];
        }
        else {
            value[i] = max(value[i-1], value[i-2]+num[i]);
        }
    }
    return value[n-1];
}


int main()
{
    vector<int> num;
    num.push_back(2);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
//    num.push_back(5);
//    num.push_back(6);
//    num.push_back(7);
    cout<<"House Robber: "<<rob(num)<<endl;
    return 0;
}
