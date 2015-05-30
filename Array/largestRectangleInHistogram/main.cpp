
//Largest Rectangle in Histogram

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& height)
{
    int length = height.size();
    if(length == 0)
        return 0;
    int heightMin = 0;
    int tmp = 0;
    int area = 0;
    for(int i = 0; i < length; i++) {
        heightMin = height[i];
        tmp = 0;
        for(int j = i; j < length; j++) {
            heightMin = min(heightMin, height[j]);
            tmp = max(tmp, heightMin*(j-i+1));
        }
        area = max(tmp, area);
    }
    return area;
}

int main()
{
    vector<int> height;
    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(2);
    height.push_back(3);
    int result = largestRectangleArea(height);
    cout<<"The result is: "<<result<<endl;
    return 0;
}
