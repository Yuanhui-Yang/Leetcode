264. Ugly Number II
https://leetcode.com/problems/ugly-number-ii/

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) {
            return n;
        }
        vector<int> A;
        A.push_back(1);
        int p2 = 0, p3 = 0, p5 = 0;
        while (A.size() < n) {
            while (p2 < A.size() and A[p2] * 2 <= A.back()) {
                ++p2;
            }
            while (p3 < A.size() and A[p3] * 3 <= A.back()) {
                ++p3;
            }
            while (p5 < A.size() and A[p5] * 5 <= A.back()) {
                ++p5;
            }
            int min_val = min(A[p2] * 2, min(A[p3] * 3, A[p5] * 5));
            A.push_back(min_val);
        }
        return A.back();
    }
};

int main(void) {
    Solution solution;
    int n, result;

    n = 10;
    result = solution.nthUglyNumber(n);
    cout << result << '\n';

    return 0;
}