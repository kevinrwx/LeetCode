

//Remove Duplicates from Sorted Array II


#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n)
{
    int length = 0;
    int num = 1;
    if(n == 0)
        return length;
    else
    {
        for(int i = 1; i < n; i++)
        {
            if(A[length] == A[i])
            {
                if(num > 0)
                {
                    A[++length] = A[i];
                    num--;
                }
            }
            else
            {
                A[++length] = A[i];
                num = 1;
            }
        }
        return (length+1);
    }
}

int main()
{
    //
//    int A[] = {1,1,2,2,2,3};
    int A[] = {1,1,1,2,2,3};
    int N = sizeof(A)/sizeof(A[0]);
    int len = removeDuplicates(A, N);
    cout<<"len is: "<<len<<endl;
    for(int i = 0; i < len; i++)
        cout<<A[i]<<' ';
    cout<<endl;
    return 0;
}



