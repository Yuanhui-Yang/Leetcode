/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 *
 * https://leetcode.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (54.76%)
 * Likes:    772
 * Dislikes: 137
 * Total Accepted:    38.4K
 * Total Submissions: 70.1K
 * Testcase Example:  '"00110"'
 *
 * Give a string s, count the number of non-empty (contiguous) substrings that
 * have the same number of 0's and 1's, and all the 0's and all the 1's in
 * these substrings are grouped consecutively. 
 * 
 * Substrings that occur multiple times are counted the number of times they
 * occur.
 * 
 * Example 1:
 * 
 * Input: "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive
 * 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 * Notice that some of these substrings repeat and are counted the number of
 * times they occur.
 * Also, "00110011" is not a valid substring because all the 0's (and 1's) are
 * not grouped together.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
 * number of consecutive 1's and 0's.
 * 
 * 
 * 
 * Note:
 * s.length will be between 1 and 50,000.
 * s will only consist of "0" or "1" characters.
 * 
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int sz = s.size();
        int i = 0;
        int prev = 0;
        int result = 0;
        while (i < sz)
        {
            int curr = 0;
            char ch = s[i];
            while (i < sz and s[i] == ch)
            {
                ++i;
                ++curr;
            }
            result += min(prev, curr);
            prev = curr;
        }
        return result;
    }
};