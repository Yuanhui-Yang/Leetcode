29. Divide Two Integers
https://leetcode.com/problems/divide-two-integers/

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        long c = f1(dividend, divisor);
        return c >= INT_MAX ? INT_MAX : c <= INT_MIN ? INT_MIN : c;
    }
private:
    long f1(long a, long b) {
        if (a < 0) {
            return -f1(-a, b);
        }
        if (b < 0) {
            return -f1(a, -b);
        }
        long x = 0, y = a + 1;
        while (x < y) {
            long z = x + (y - x) / 2;
            if (f2(a, b, z)) {
                x = z + 1;
            }
            else {
                y = z;
            }
        }
        return --x;
    }
    bool f2(long a, long b, long z) {
        return b * z <= a;
    }
};

int main(void) {
    Solution solution;
    int dividend, divisor, result;
    
    dividend = -2147483648;
    divisor = 1;
    result = solution.divide(dividend, divisor);
    cout << result << '\n';

    dividend = 1;
    divisor = 2;
    result = solution.divide(dividend, divisor);
    cout << result << '\n';
    
    return 0;
}