69. Sqrt(x)
https://leetcode.com/problems/sqrtx/

Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.


Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        return f2(x);
    }
private:
    long f1(long x) {
        long i = 0, j = x + 1;
        while (i < j) {
            long k = i + (j - i) / 2, value = k * k;
            if (value <= x) {
                i = k + 1;
            }
            else {
                j = k;
            }
        }
        return i - 1;
    }
    long f2(long x) {
        long r = x;
        while (r * r > x) {
            r = (r + x / r) / 2; 
        }
        return r;
    }
};

int main(void) {
    Solution solution;
    int x, result;
    
    x = 4;
    result = solution.mySqrt(x);
    cout << result << '\n';

    x = 8;
    result = solution.mySqrt(x);
    cout << result << '\n';
    
    return 0;
}