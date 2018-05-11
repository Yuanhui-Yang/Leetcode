830. Positions of Large Groups
https://leetcode.com/problems/positions-of-large-groups/

In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.

 

Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
 

Note:  1 <= S.length <= 1000

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int sz = S.size(), i = 0, j = 0;
        vector<vector<int>> result;
        while (j < sz) {
            i = j;
            while (j + 1 < sz and S[j] == S[j + 1]) {
                ++j;
            }
            if (j - i >= 2) {
                result.push_back({i, j});
            }
            ++j;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string S;
    vector<vector<int>> result;

    S = "abbxxxxzzy";
    result = solution.largeGroupPositions(S);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }

    return 0;
}
