790. Domino and Tromino Tiling
https://leetcode.com/problems/domino-and-tromino-tiling/

We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.

XX  <- domino

XX  <- "L" tromino
X
Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.

(In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)

Example:
Input: 3
Output: 5
Explanation: 
The five different ways are listed below, different letters indicates different tiles:
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY
Note:

N  will be in range [1, 1000].

#include <iostream>

using namespace std;

class Solution {
public:
    int numTilings(int N) {
        if (N <= 0) {
            return 0;
        }
        if (N == 1) {
            return 1;
        }
        if (N == 2) {
            return 2;
        }
        long a0 = 1, a1 = 1, a2 = 2, a3 = 2, M = 1e9 + 7;
        while (N-- >= 3) {
            a3 = (2 * a2 + a0) % M;
            a0 = a1 % M;
            a1 = a2 % M;
            a2 = a3 % M;
        }
        return a3;
    }
};

int main(void) {
    Solution solution;
    int N, result;

    N = 3;
    result = solution.numTilings(N);
    cout << result << '\n';

    return 0;
}
