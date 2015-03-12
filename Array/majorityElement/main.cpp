
//Majority Element

#include <iostream>
<<<<<<< HEAD
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
=======
#include <unordered_map>
#include <vector>

using namespace std;

////hash table
//int majorityElement(vector<int> &num)
//{
//    unordered_map<int, int> mapping;
//    int len = num.size();
//    for(int i = 0; i < len; i++) {
>>>>>>> 0d3afb4c9914432414a38497c0a2e550b7e28fcc
//        if(mapping.find(num[i]) == mapping.end())
//            mapping[num[i]] = 0;
//        else
//            mapping[num[i]]++;
<<<<<<< HEAD
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
=======
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
>>>>>>> 0d3afb4c9914432414a38497c0a2e550b7e28fcc
            candinate = num[i];
            nTimes = 1;
        }
        else {
<<<<<<< HEAD
            //
            if(candinate != num[i])
                nTimes--;
            else
                nTimes++;
=======
            if(candinate == num[i])
                nTimes++;
            else
                nTimes--;
>>>>>>> 0d3afb4c9914432414a38497c0a2e550b7e28fcc
        }
    }
    return candinate;
}

<<<<<<< HEAD

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
=======
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

>>>>>>> 0d3afb4c9914432414a38497c0a2e550b7e28fcc
