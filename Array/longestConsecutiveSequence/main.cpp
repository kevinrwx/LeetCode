

//Longest Consecutive Sequence

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int longestConsecutive(vector<int> &num)
{
    unordered_map<int, bool> used;

    for(auto i : num)
        used[i] = false;

    int longest = 0;
    for(auto i : num)
    {
        if(used[i])
            continue;

        int length = 1;
        used[i] = true;
        for(int j = i + 1; used.find(j) != used.end(); ++j)
        {
            used[j] = true;
            length++;
        }
        for(int j = i - 1; used.find(j) != used.end(); j--)
        {
            used[j] = true;
            length++;
        }
        longest = max(longest, length);
    }
    return longest;
}

int main()
{
    int A[] = {100, 4, 200, 1, 3, 2};
    int N = sizeof(A)/sizeof(A[0]);
    int longest;
    vector<int> nums;
    for(inti = 0; i < N; i++)
        nums.push_back(A[i]);
    longest = longestConsecutive(nums);
    cout<<"Longest Consecutive sequsence is: "<<longest<<endl;
    return 0;
}
