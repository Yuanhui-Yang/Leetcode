#include <iostream>
#include <array>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size(), i = sz - 2;
        stack<array<int, 2>> stk;
        stk.push({temperatures.back(), sz - 1});
        vector<int> result(sz, 0);
        while (i >= 0) {
            while (!stk.empty() and stk.top()[0] <= temperatures[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                result[i] = 0;
            }
            else {
                result[i] = stk.top()[1] - i;
            }
            stk.push({temperatures[i], i});
            --i;
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
