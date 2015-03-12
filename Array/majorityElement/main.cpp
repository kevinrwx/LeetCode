
//Majority Element

#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;


//hash table
//int majorityElement(vector<int> &num)
//{
//    //
//    std::tr1::unordered_map<int, int> mapping;
//    int len = num.size();
//    for(int i = 0; i < len; i++) {
//        //
//        if(mapping.find(num[i]) == mapping.end())
//            mapping[num[i]] = 0;
//        else
//            mapping[num[i]]++;
//        if(mapping[num[i]] >= len/2)
//            return num[i];
//    }
//}

//Moore's voting algorithm
int majorityElement(vector<int> &num)
{
    //
    int nTimes = 0;
    int candinate = 0;
    for(int i = 0; i < num.size(); i++) {
        if(nTimes == 0) {
            //
            candinate = num[i];
            nTimes = 1;
        }
        else {
            //
            if(candinate != num[i])
                nTimes--;
            else
                nTimes++;
        }
    }
    return candinate;
}


int main()
{
    //
    vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(5);
    numbers.push_back(2);
    numbers.push_back(2);
    numbers.push_back(2);
    cout<<"Majority Element is: "<<majorityElement(numbers)<<endl;
    return 0;
}
