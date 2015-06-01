
//Largest Rectangle in Histogram

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


////O(n*n)复杂度，对于数据较多的情况会超时
//int largestRectangleArea(vector<int>& height)
//{
//    int length = height.size();
//    if(length == 0)
//        return 0;
//    int heightMin = 0;
//    int tmp = 0;
//    int area = 0;
//    for(int i = 0; i < length; i++) {
//        heightMin = height[i];
//        tmp = 0;
//        for(int j = i; j < length; j++) {
//            heightMin = min(heightMin, height[j]);
//            tmp = max(tmp, heightMin*(j-i+1));
//        }
//        area = max(tmp, area);
//    }
//    return area;
//}


//O(n)的复杂度
int largestRectangleArea(vector<int> &heights)
{
    int length = heights.size();
    if(length == 0)
        return 0;
    stack<int> s;
    heights.push_back(0);
    length = heights.size();
    int area = 0;
    int tmp = 0;
    int i = 0;
    while(i < length) {
        if(s.empty() || heights[s.top()] <= heights[i])
            s.push(i++);
        else {
            tmp = s.top();
            s.pop();
            area = max(area, heights[tmp] * (s.empty() ? i : i - s.top() - 1));
        }
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
