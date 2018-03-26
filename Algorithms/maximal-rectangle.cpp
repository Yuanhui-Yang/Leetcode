85. Maximal Rectangle
https://leetcode.com/problems/maximal-rectangle/

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> A;
        int X = matrix.size(), Y = X == 0 ? 0 : matrix[0].size();
        for (int j = 0; j < Y; ++j) {
            int val = matrix[0][j] == '0' ? 0 : 1;
            A.push_back(val);
        }
        int result = f1(A);
        for (int i = 1; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (matrix[i][j] == '0') {
                    A[j] = 0;
                }
                else {
                    ++A[j];
                }
            }
            result = max(result, f1(A));
        }
        return result;
    }
private:
    int f1(vector<int> & A) {
        A.push_back(0);
        stack<int> stk;
        stk.push(-1);
        int sz = A.size(), i = 0, result = 0;
        while (i < sz) {
            while (stk.top() >= 0 and A[stk.top()] > A[i]) {
                int top = stk.top();
                stk.pop();
                result = max(result, (i - stk.top() - 1) * A[top]);
            }
            stk.push(i);
            ++i;
        }
        A.pop_back();
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<vector<char>> matrix;
    int result;

    matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    result = solution.maximalRectangle(matrix);
    cout << result << '\n';

    return 0;
}