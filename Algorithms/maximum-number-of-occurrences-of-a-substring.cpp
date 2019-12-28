/*
 * @lc app=leetcode id=1297 lang=cpp
 *
 * [1297] Maximum Number of Occurrences of a Substring
 *
 * https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/
 *
 * algorithms
 * Medium (43.92%)
 * Likes:    54
 * Dislikes: 55
 * Total Accepted:    4.3K
 * Total Submissions: 9.7K
 * Testcase Example:  '"aababcaab"\n2\n3\n4'
 *
 * Given a string s, return the maximum number of ocurrences of any substring
 * under the following rules:
 * 
 * 
 * The number of unique characters in the substring must be less than or equal
 * to maxLetters.
 * The substring size must be between minSize and maxSize inclusive.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
 * Output: 2
 * Explanation: Substring "aab" has 2 ocurrences in the original string.
 * It satisfies the conditions, 2 unique letters and size 3 (between minSize
 * and maxSize).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
 * Output: 2
 * Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
 * Output: 3
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 1 <= maxLetters <= 26
 * 1 <= minSize <= maxSize <= min(26, s.length)
 * s only contains lowercase English letters.
 * 
 */

// @lc code=start
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int sz = s.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int result = 0;
        array<int, 26> A;
        A.fill(0);
        unordered_map<string, int> B;
        while (j < sz)
        {
            if (A[s[j++] - 'a']++ == 0)
            {
                ++cnt;
            }
            while (i < j and cnt > maxLetters)
            {
                if (--A[s[i++] - 'a'] == 0)
                {
                    --cnt;
                }
            }
            int left = j - maxSize;
            int right = j - minSize;
            for (int k = max(i, left); k <= right; ++k)
            {
                string t = s.substr(k, j - k);
                result = max(result, ++B[t]);
            }
        }
        return result;
    }
};
// @lc code=end

