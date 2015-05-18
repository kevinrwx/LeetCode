
//Triangle

#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle)
{
    vector<int> result;
    int height = triangle.size();
    int len;
    int maxmum;
    if(height == 0)
        return 0;
    for(int i = height-1; i >= 0; i--) {
        len = triangle[i].size();
        if(i == (height-1)) {
            for(int j = 0; j < len; j++) {
                result.push_back(triangle[i][j]);
            }
        }
        else {
            for(int k = 0; k < len; k++) {
                maxmum = result[k] < result[k+1] ? result[k] : result[k+1];
                result[k] = maxmum + triangle[i][k];
            }
        }
    }
    return result[0];
}

int main()
{
    vector<vector<int> > nums;

    vector<int> number;
    nums.push_back(number);
    nums[0].push_back(2);

    nums.push_back(number);
    nums[1].push_back(3);
    nums[1].push_back(4);

    nums.push_back(number);
    nums[2].push_back(6);
    nums[2].push_back(5);
    nums[2].push_back(7);

    nums.push_back(number);
    nums[3].push_back(4);
    nums[3].push_back(1);
    nums[3].push_back(8);
    nums[3].push_back(3);

    int result;
    result = minimumTotal(nums);
    cout<<"The result is: "<<result;
    return 0;
}
