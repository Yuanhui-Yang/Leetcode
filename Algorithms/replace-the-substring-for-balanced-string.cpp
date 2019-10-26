/*
 * @lc app=leetcode id=1234 lang=cpp
 *
 * [1234] Replace the Substring for Balanced String
 *
 * https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/
 *
 * algorithms
 * Medium (29.13%)
 * Likes:    85
 * Dislikes: 21
 * Total Accepted:    4K
 * Total Submissions: 13.6K
 * Testcase Example:  '"QWER"'
 *
 * You are given a string containing only 4 kinds of characters 'Q', 'W', 'E'
 * and 'R'.
 * 
 * A string is said to be balanced if each of its characters appears n/4 times
 * where n is the length of the string.
 * 
 * Return the minimum length of the substring that can be replaced with any
 * other string of the same length to make the original string s balanced.
 * 
 * Return 0 if the string is already balanced.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "QWER"
 * Output: 0
 * Explanation: s is already balanced.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "QQWE"
 * Output: 1
 * Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is
 * balanced.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "QQQW"
 * Output: 2
 * Explanation: We can replace the first "QQ" to "ER". 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "QQQQ"
 * Output: 3
 * Explanation: We can replace the last 3 'Q' to make s = "QWER".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s.length is a multiple of 4
 * s contains only 'Q', 'W', 'E' and 'R'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int balancedString(string s) {
        int sz = s.size(), n = sz / 4, result = sz;
        int i = 0, j = 0;
        unordered_map<char, int> A;
        for (const auto& i : s)
        {
            ++A[i];
        }
        while (j < sz)
        {
            --A[s[j++]];
            while (i <= j and f1(A, n))
            {
                result = min(result, j - i);
                ++A[s[i++]];
            }
        }
        return result;
    }
private:
    bool f1(unordered_map<char, int>& A, int cap)
    {
        for (const auto& i : A)
        {
            int val = i.second;
            if (val > cap)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end