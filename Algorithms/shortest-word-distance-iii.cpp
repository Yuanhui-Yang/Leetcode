/*
 * @lc app=leetcode id=245 lang=cpp
 *
 * [245] Shortest Word Distance III
 *
 * https://leetcode.com/problems/shortest-word-distance-iii/description/
 *
 * algorithms
 * Medium (54.03%)
 * Likes:    135
 * Dislikes: 59
 * Total Accepted:    41.9K
 * Total Submissions: 77.4K
 * Testcase Example:  '["practice", "makes", "perfect", "coding", "makes"]\n"makes"\n"coding"'
 *
 * Given a list of words and two words word1 and word2, return the shortest
 * distance between these two words in the list.
 * 
 * word1 and word2 may be the same and they represent two individual words in
 * the list.
 * 
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * 
 * Input: word1 = “makes”, word2 = “coding”
 * Output: 1
 * 
 * 
 * 
 * Input: word1 = "makes", word2 = "makes"
 * Output: 3
 * 
 * 
 * Note:
 * You may assume word1 and word2 are both in the list.
 * 
 */
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int sz = words.size(), result = sz;
        for (int i = 0, a = -1, b = -1; i < sz; ++i)
        {
            string& word = words[i];
            if (word1 == word2)
            {
                if (word == word1)
                {
                    if (a < 0)
                    {
                        a = i;
                    }
                    else if (b < 0)
                    {
                        b = i;
                    }
                    else if (a < b)
                    {
                        a = i;
                    }
                    else
                    {
                        b = i;
                    }
                }
            }
            else
            {
                if (word == word1)
                {
                    a = i;
                }
                else if (word == word2)
                {
                    b = i;
                }
            }
            if (a >= 0 and b >= 0)
            {
                result = min(result, abs(a - b));
            }
        }
        return result;
    }
};