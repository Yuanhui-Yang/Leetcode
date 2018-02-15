756. Pyramid Transition Matrix
https://leetcode.com/problems/pyramid-transition-matrix/

We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.

For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.

We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:
Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  D   E
 / \ / \
X   Y   Z

This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
Example 2:
Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
Note:
bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        return f1(bottom, 0, "", allowed);
    }
private:
    bool f1(string curr_bottom, int begin, string next_bottom, vector<string>& allowed) {
        int end = curr_bottom.size();
        if (end == 1) {
            return true;
        }
        if (end - begin <= 1) {
            return f1(next_bottom, 0, "", allowed);
        }
        for (const auto & i : allowed) {
            if (curr_bottom[begin] == i[0] and curr_bottom[begin + 1] == i[1]) {
                next_bottom.push_back(i[2]);
                if (f1(curr_bottom, begin + 1, next_bottom, allowed)) {
                    return true;
                }
                next_bottom.pop_back();
            }
        }
        return false;
    }
};

int main(void) {
    Solution solution;
    string bottom;
    vector<string> allowed;
    bool result;
    
    bottom = "XYZ";
    allowed = {"XYD", "YZE", "DEA", "FFF"};
    result = solution.pyramidTransition(bottom, allowed);
    cout << boolalpha << result << '\n';
    
    return 0;
}