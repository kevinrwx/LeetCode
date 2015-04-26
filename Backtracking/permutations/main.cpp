
//Permutations

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<vector<int>> &num)
{
    //
    if(num.size() == 0)
        cout<<"Empty vector"<<endl;
    for(size_t i = 0; i < num.size(); i++) {
        for(size_t j = 0; j < num[i].size(); j++)
            cout<<num[i][j]<<" ";
        cout<<endl;
    }
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void addToVector(vector<vector<int>> &nums, vector<int> &ins)
{
    vector<int> instance;
    nums.push_back(instance);
    vector<vector<int>>::iterator it = nums.end() - 1;
    for(size_t i = 0; i < ins.size(); i++) {
        (*it).push_back(ins[i]);
    }
}

void permuteVector(vector<vector<int>> &res, vector<int> &num, int i, int n)
{
    int j;
    if(i == n)
        addToVector(res, num);
    else {
        for(j = i; j <= n; j++) {
            Swap(&num[i], &num[j]);
            permuteVector(res, num, i+1, n);
            Swap(&num[i], &num[j]);
        }
    }
}

vector<vector<int>> permute(vector<int> &num)
{
    vector<vector<int>> res;
    int len = num.size();
    if(len == 0)
        return res;
    permuteVector(res, num, 0, len-1);
//    printVector(res);
    return res;
}

int main()
{
    vector<int> number;
    number.push_back(1);
    number.push_back(2);
    number.push_back(3);

    permute(number);
    return 0;
}


//void printPermute(vector<vector<int> > &num)
//{
//    //
//    if(num.size() == 0)
//        cout<<"Empty vector"<<endl;
//    for(size_t i = 0; i < num.size(); i++) {
//        for(size_t j = 0; j < num[i].size(); j++)
//            cout<<num[i][j]<<" ";
//        cout<<endl;
//    }
//}



//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void printVector(vector<int> &num)
//{
//    if(num.size() == 0)
//        cout<<"Empty vector"<<endl;
//    for(size_t i = 0; i < num.size(); i++)
//        cout<<num[i]<<" ";
//    cout<<endl;
//}
//
//int main()
//{
//    vector<int> num;
//    num.push_back(1);
//    num.push_back(2);
//    num.push_back(3);
//    num.push_back(4);
//    num.push_back(5);
//    vector<int>::iterator it = num.end() -1;
//    cout<<*it<<endl;
//}












