
//Largest Number

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string largestNumber(vector<int> &nums)
{
    //
}

void Swap(string *x, string *y)
{
    string temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(string arr[], int l, int h)
{
    int i = l-1;
    string x = arr[h];
    for(int j = l; j <= h-1; j++) {
        if(arr[j] > x) {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i+1], &arr[h]);
    return (i+1);
}

void quickSort(string arr[], int l, int h)
{
    if(l < h) {
        int p = Partition(arr, l, h);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
    }
}

void printArray(string arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
//    string s1 = "30";
//    string s2 = "9";
////    if(s1 < s2)
////        cout<<s1<<endl;
////    else if(s1 > s2)
////        cout<<s2<<endl;
////    else
////        cout<<s1<<" == "<<s2<<endl;
//    string maxstr = s1 > s2 ? s1 : s2;
//    cout<<"max string: "<<maxstr<<endl;
    string arr[] = {"3", "34", "30", "5", "9"};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before quick sort: "<<endl;
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    cout<<"After quick sort: "<<endl;
    printArray(arr, n);
    return 0;
}
