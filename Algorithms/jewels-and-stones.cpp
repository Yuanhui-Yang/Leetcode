771. Jewels and Stones
https://leetcode.com/problems/jewels-and-stones/

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

#include <iostream>
#include <string>
#include <array>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        array<int, 512> A;
        A.fill(0);
        for (const auto & i : J) {
            int id = i;
            ++A[id];
        }
        int result = 0;
        for (const auto & i : S) {
            int id = i;
            result += (A[id] > 0);
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string J, S;
    int result;
    
    J = "aA";
    S = "aAAbbbb";
    result = solution.numJewelsInStones(J, S);
    cout << result << '\n';

    J = "z";
    S = "ZZ";
    result = solution.numJewelsInStones(J, S);
    cout << result << '\n';
    
    return 0;
}