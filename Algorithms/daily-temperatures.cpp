739. Daily Temperatures
https://leetcode.com/problems/daily-temperatures/

Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> A;
        int sz = temperatures.size();
        vector<int> result(sz, 0);
        if (sz <= 1) {
            return result;
        }
        for (int i = 0; i < sz; ++i) {
            while (!A.empty() and temperatures[A.top()] < temperatures[i]) {
                int top = A.top();
                A.pop();
                result[top] = i - top;
            }
            A.push(i);
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> temperatures, result;
    
    temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    result = solution.dailyTemperatures(temperatures);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}