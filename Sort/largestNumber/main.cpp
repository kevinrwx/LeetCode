
//Largest Number

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void Swap(string *x, string *y)
{
    string temp = *x;
    *x = *y;
    *y = temp;
}

int Compare(string str1, string str2)
{
    string strLjoin = str1 + str2;
    string strRjoin = str2 + str1;
    if(strLjoin > strRjoin)
        return 1;
    else if(strLjoin < strRjoin)
        return -1;
    else
        return 0;
}

int Partition(string arr[], int l, int h)
{
    int i = l-1;
    string x = arr[h];
    for(int j = l; j <= h-1; j++) {
        if(Compare(arr[j], x) > 0) {
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

string itos(int i)
{
    stringstream s;
    s << i;
    return s.str();
}

string largestNumber(vector<int> &nums)
{
    if(nums.size() == 0)
        return NULL;

    int len = nums.size();
    string str;
    string strNumber[len];

    for(size_t i = 0; i < nums.size(); i++) {
        strNumber[i] = itos(nums[i]);
        cout<<strNumber[i]<<" ";
    }
    cout<<endl;

    quickSort(strNumber, 0, len-1);

    for(int j = 0; j < len; j++) {
        str += strNumber[j];
    }

    int k = 0;
    while(k < str.length() && str[k] == '0')
        k++;
    if(k == str.length()) {
        str = '0';
        return str;
    }

    return str;
}

void printArray(string arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
//    string arr[] = {"3", "34", "30", "5", "9"};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    cout<<"Before quick sort: "<<endl;
//    printArray(arr, n);
//    quickSort(arr, 0, n-1);
//    cout<<"After quick sort: "<<endl;
//    printArray(arr, n);
//    return 0;

    vector<int> nums;
//    nums.push_back(9);
//    nums.push_back(5);
//    nums.push_back(30);
//    nums.push_back(34);
//    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(0);
    cout<<"Before Largest Number: ";
    for(size_t i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;

    string result = largestNumber(nums);
    cout<<"Result is: "<<result<<endl;
    return 0;
}


















