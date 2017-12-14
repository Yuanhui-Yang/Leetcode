// 744. Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

/*
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"
Note:
letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique letters.
target is a lowercase letter.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<char>::iterator a = upper_bound(letters.begin(), letters.end(), target), b = letters.end();
        return a == b ? letters.front() : *a;
    }
};

int main(void) {
    Solution solution;
    vector<char> letters;
    char target, result;

    letters = {'c', 'f', 'j'};
    target = 'a';
    result = solution.nextGreatestLetter(letters, target);
    cout << result << '\n';

    letters = {'c', 'f', 'j'};
    target = 'c';
    result = solution.nextGreatestLetter(letters, target);
    cout << result << '\n';

    letters = {'c', 'f', 'j'};
    target = 'd';
    result = solution.nextGreatestLetter(letters, target);
    cout << result << '\n';

    letters = {'c', 'f', 'j'};
    target = 'g';
    result = solution.nextGreatestLetter(letters, target);
    cout << result << '\n';

    letters = {'c', 'f', 'j'};
    target = 'j';
    result = solution.nextGreatestLetter(letters, target);
    cout << result << '\n';

    letters = {'c', 'f', 'j'};
    target = 'k';
    result = solution.nextGreatestLetter(letters, target);
    cout << result << '\n';

    return 0;
}