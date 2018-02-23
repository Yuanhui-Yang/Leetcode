84. Largest Rectangle in Histogram
https://leetcode.com/problems/largest-rectangle-in-histogram/

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(INT_MIN);
        int sz = heights.size(), i = 0, result = 0;
        stack<int> stk;
        while (i < sz) {
            while (!stk.empty() and heights[stk.top()] > heights[i]) {
                int top = stk.top();
                stk.pop();
                int area = (stk.empty() ? i : (i - stk.top() - 1)) * heights[top];
                result = max(result, area);
            }
            stk.push(i);
            ++i;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    
    vector<int> heights;
    int result;
    
    heights = {2,1,5,6,2,3};
    result = solution.largestRectangleArea(heights);
    cout << result << '\n';
    
    return 0;
}