50. Pow(x, n)
https://leetcode.com/problems/powx-n/

Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        return f1(x, n);
    }
private:
    double f1(double x, long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 1 / f1(x, -n);
        }
        double y = f1(x, n / 2);
        return n % 2 ? x * y * y : y * y;
    }
};

int main(void) {
    Solution solution;
    double x, answer, result;
    int n;

    x = 2.00000;
    n = -2147483648;
    result = solution.myPow(x, n);
    cout << result << '\n';
    
    return 0;
}