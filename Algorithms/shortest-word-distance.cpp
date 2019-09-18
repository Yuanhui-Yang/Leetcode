/*
 * @lc app=leetcode id=243 lang=cpp
 *
 * [243] Shortest Word Distance
 *
 * https://leetcode.com/problems/shortest-word-distance/description/
 *
 * algorithms
 * Easy (58.42%)
 * Likes:    306
 * Dislikes: 30
 * Total Accepted:    75K
 * Total Submissions: 128.1K
 * Testcase Example:  '["practice", "makes", "perfect", "coding", "makes"]\n"coding"\n"practice"'
 *
 * Given a list of words and two words word1 and word2, return the shortest
 * distance between these two words in the list.
 * 
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * 
 * Input: word1 = “coding”, word2 = “practice”
 * Output: 3
 * 
 * 
 * 
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 * 
 * 
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are
 * both in the list.
 * 
 */
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int sz = words.size(), result = sz;
        for (int i = 0, a = -1, b = -1; i < sz; ++i)
        {
            string& word = words[i];
            if (word == word1)
            {
                a = i;
            }
            else if (word == word2)
            {
                b = i;
            }
            if (a >= 0 and b >= 0)
            {
                result = min(result, abs(a - b));
            }
        }
        return result;
    }
};