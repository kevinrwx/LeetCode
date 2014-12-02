

//Median of Two Sorted Arrays

#include <iostream>

using namespace std;

int find_kth(int A[], int m , int B[], int n, int k)
{
    //
    if(m > n)
        return find_kth(B, n, A, m, k);
    if(m == 0)
        return B[k-1];
    if(k == 1)
        return min(A[0], B[0]);

    int ia = min(k/2, m);
    int ib = k - ia;
    if(A[ia - 1] < B[ib - 1])
        return find_kth(A + ia, m - ia, B, n, k - ia);
    else if(A[ia - 1] > B[ib - 1])
        return find_kth(A, m, B + ib, n - ib, k - ib);
    else
        return A[ia - 1];
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    //
    int total = m + n;
    if(total % 2 != 0)
        return find_kth(A, m, B, n, total/2 + 1);
    else
        return (find_kth(A, m, B, n, total/2) + find_kth(A, m, B, n, total/2 + 1)) / 2.0;
}


int main()
{
    //
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8, 10, 11};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
//    int k = 3;
    double num = findMedianSortedArrays(A, m, B, n);
//    cout<<"The "<<k<<"th num is: "<<num<<endl;
    cout<<"The median number is: "<<num<<endl;
    return 0;
}
