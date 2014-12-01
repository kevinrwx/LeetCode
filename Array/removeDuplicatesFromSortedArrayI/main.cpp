

//remove duplicates from sorted array I

#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n)
{
    //
    int length = 0;
    if(n == 0)
        return length;
    else
    {
        for(int i = 1; i < n; i++)
            if(A[length] != A[i])
                A[++length] = A[i];
        return (length+1);
    }
}

int main()
{
    //
    int A[] = {1,1,2,2,3,4,4,6,7,8,8,9};
    int N = sizeof(A)/sizeof(A[0]);
    int len = removeDuplicates(A, N);
    cout<<"len is: "<<len<<endl;
    for(int i = 0; i < len; i++)
        cout<<A[i]<<' ';
    cout<<endl;
}

