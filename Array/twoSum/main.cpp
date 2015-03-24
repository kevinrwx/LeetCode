

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    unordered_map<int, int> mapping;
    vector<int> result;
    for(int i = 0; i < numbers.size(); i++) {
        mapping[numbers[i]] = i;
    }
    for(int i = 0; i < numbers.size(); i++) {
        const int gap = target - numbers[i];
        if(mapping.find(gap) != mapping.end() && mapping[gap] != i) {
            result.push_back(i + 1);
            result.push_back(mapping[gap] + 1);
            break;
        }
    }
    return result;
}

int main()
{
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(15);
    int target = 13;
    vector<int> resu = twoSum(numbers, target);
    cout<<"Index1: "<<resu[0]<<" Index2: "<<resu[1];
    return 0;
}
