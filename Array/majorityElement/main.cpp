
//Majority Element

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

////hash table
//int majorityElement(vector<int> &num)
//{
//    unordered_map<int, int> mapping;
//    int len = num.size();
//    for(int i = 0; i < len; i++) {
//        if(mapping.find(num[i]) == mapping.end())
//            mapping[num[i]] = 0;
//        else
//            mapping[num[i]]++;
//    }
//    for(int j = 0; j < len; j++) {
//        if(mapping[num[j]] >= len/2)
//            return num[j];
//    }
//}

//Moore voting algorithm
int majorityElement(vector<int> &num)
{
    //
    int candinate = 0;
    int nTimes = 0;
    for(int i = 0; i < num.size(); i++) {
        if(nTimes == 0) {
            candinate = num[i];
            nTimes = 1;
        }
        else {
            if(candinate == num[i])
                nTimes++;
            else
                nTimes--;
        }
    }
    return candinate;
}

int main()
{
    vector<int> v;
    v.push_back(6);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(7);
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    cout<<"majority element: "<<majorityElement(v)<<endl;
    return 0;
}

