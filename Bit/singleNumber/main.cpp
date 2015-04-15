
//single number

#include <iostream>

using namespace std;

int singleNumber(int A[], int n)
{
    int num = 0;
    if(A == NULL)
        return 0;
    for(int i = 0; i < n; i++)
        num = num ^ A[i];
    return num;
}

int main()
{
    int A[] = {1,1,2,2,3,3,4};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"The number is: "<<singleNumber(A, n)<<endl;
    return 0;
}
