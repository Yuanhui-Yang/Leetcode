858. Mirror Reflection
https://leetcode.com/problems/mirror-reflection/

There is a special square room with mirrors on each of the four walls.  Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.

The square room has walls of length p, and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.

Return the number of the receptor that the ray meets first.  (It is guaranteed that the ray will meet a receptor eventually.)

 

Example 1:

Input: p = 2, q = 1
Output: 2
Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.



Note:

1 <= p <= 1000
0 <= q <= p

#include <iostream>

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int y = lcm(p, q);
        int x = y * p / q;
        int m = x / p;
        int n = y / p;
        if (n % 2 == 0) {
            return 0;
        }
        else if (m % 2 == 0) {
            return 2;
        }
        else {
            return 1;
        }
    }
private:
    int lcm(int p, int q) {
        int d = gcd(p, q);
        return p * q / d;
    }
    int gcd(int p, int q) {
        if (p < q) {
            return gcd(q, p);
        }
        if (q == 0) {
            return p;
        }
        return gcd(q, p % q);
    }
};

int main(void) {
    Solution solution;
    int p, q, result;

    p = 2;
    q = 1;
    result = solution.mirrorReflection(p, q);
    cout << result << '\n';

    return 0;
}
