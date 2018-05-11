816. Ambiguous Coordinates
https://leetcode.com/problems/ambiguous-coordinates/

We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then, we removed all commas, decimal points, and spaces, and ended up with the string S.  Return a list of strings representing all possibilities for what our original coordinates could have been.

Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.  Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".

The final answer list can be returned in any order.  Also note that all coordinates in the final answer have exactly one space between them (occurring after the comma.)

Example 1:
Input: "(123)"
Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
Example 2:
Input: "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation: 
0.0, 00, 0001 or 00.01 are not allowed.
Example 3:
Input: "(0123)"
Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
Example 4:
Input: "(100)"
Output: [(10, 0)]
Explanation: 
1.0 is not allowed.
 

Note:

4 <= S.length <= 12.
S[0] = "(", S[S.length - 1] = ")", and the other elements in S are digits.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> result;
        for (int sz = S.size(), i = 1; i <= sz - 2; ++i) {
            vector<string> a = f1(S.substr(1, i)), b = f1(S.substr(i + 1, sz - 2 - i));
            for (const auto & j : a) {
                for (const auto & k : b) {
                    string l = "(" + j + ", " + k + ")";
                    result.push_back(l);
                }
            }
        }
        return result;
    }
private:
    vector<string> f1(string s) {
        vector<string> result;
        for (int sz = s.size(), i = 1; i <= sz; ++i) {
            string a = s.substr(0, i), b = s.substr(i);
            if (a.front() != '0' or i == 1) {
                if (i == sz or b.back() != '0') {
                    string c = a + (b.empty() ? "" : "." + b);
                    result.push_back(c);
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string S;
    vector<string> result;

    S = "(123)";
    result = solution.ambiguousCoordinates(S);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    S = "(00011)";
    result = solution.ambiguousCoordinates(S);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    S = "(0123)";
    result = solution.ambiguousCoordinates(S);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    S = "(100)";
    result = solution.ambiguousCoordinates(S);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}
