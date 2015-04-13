
//Gas Station


#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    vector<int> bala;
    int sum = 0;
    int index;
    for(vector<int>::size_type i = 0; i != gas.size(); i++) {
        bala.push_back(gas[i] - cost[i]);
        sum += bala[i];
    }

    for(vector<int>::size_type j = 0; j != bala.size(); j++) {
        sum = sum -bala[j] + bala[];
        if()
    }
    return index;
}

int main()
{
    vector<int> gas;
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(4);
    gas.push_back(5);
    gas.push_back(6);

    vector<int> cost;
    cost.push_back(1);
    cost.push_back(2);
    cost.push_back(3);
    cost.push_back(4);
    cost.push_back(5);

    canCompleteCircuit(gas, cost);
//    for(vector<int>::size_type i = 0; i != gas.size(); i++)
//        cout<<cost[i]<<" ";
//    cout<<endl;
    return 0;

}
