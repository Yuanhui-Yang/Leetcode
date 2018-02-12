777. Swap Adjacent in LR String
https://leetcode.com/problems/swap-adjacent-in-lr-string/

In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Note:

1 <= len(start) = len(end) <= 10000.
Both start and end will only consist of characters in {'L', 'R', 'X'}.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int sz = start.size(), i = 0, j = 0, a = 0, b = 0;
        while (i < sz and j < sz) {
            while (i < sz and start[i] == 'X') {
                ++i;
            }
            while (j < sz and end[j] == 'X') {
                ++j;
            }
            if (i == sz and j == sz) {
            }
            else if (i < sz and j < sz and start[i] == end[j]) {
                ++i;
                ++j;
            }
            else {
                return false;
            }
        }
        i = 0;
        a = 0;
        b = 0;
        while (i < sz) {
            if (start[i] == 'R') {
                ++a;
            }
            if (end[i] == 'R') {
                ++b;
            }
            if (a < b) {
                return false;
            }
            ++i;
        }
        i = sz - 1;
        a = 0;
        b = 0;
        while (i >= 0) {
            if (start[i] == 'L') {
                ++a;
            }
            if (end[i] == 'L') {
                ++b;
            }
            if (a < b) {
                return false;
            }
            --i;
        }
        return true;
    }
};

int main(void) {
    Solution solution;
    string start, end;
    bool result;
    
    start = "RXXLRXRXL";
    end = "XRLXXRRLX";
    result = solution.canTransform(start, end);
    cout << boolalpha << result << '\n';
    
    return 0;
}