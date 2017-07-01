// 246. Strobogrammatic Number
// https://leetcode.com/problems/strobogrammatic-number/

/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int m[10];
        m[0] = 0;
        m[1] = 1;
        m[2] = -1;
        m[3] = -1;
        m[4] = -1;
        m[5] = -1;
        m[6] = 9;
        m[7] = -1;
        m[8] = 8;
        m[9] = 6;
        int n = num.size(), i = 0, j = n - 1;
        if ((n & 1) and num[n / 2] -'0' != m[num[n / 2] - '0']) {
            return false;
        }
        while (i < j) {
            if (num[i] - '0' != m[num[j] - '0']) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};