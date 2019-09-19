/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.28%)
 * Likes:    440
 * Dislikes: 1812
 * Total Accepted:    297.3K
 * Total Submissions: 920.8K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int sz = s.size(), i = sz - 1;
        while (i >= 0 and s[i] == ' ')
        {
            --i;
            --sz;
        }
        while (i >= 0 and s[i] != ' ')
        {
            --i;
        }
        return sz - i - 1;
    }
};