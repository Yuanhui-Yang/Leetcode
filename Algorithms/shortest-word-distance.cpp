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
        unordered_map<string, vector<int>> A = f1(words);
        vector<int>& x = A[word1], &y = A[word2];
        int sz1 = x.size(), sz2 = y.size(), i = 0, j = 0, result = words.size();
        while (i < sz1 and j < sz2)
        {
            int a = x[i], b = y[j];
            result = min(result, abs(a - b));
            if (a < b)
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return result;
    }
private:
    unordered_map<string, vector<int>> f1(vector<string>& words)
    {
        unordered_map<string, vector<int>> result;
        for (int sz = words.size(), i = 0; i < sz; ++i)
        {
            result[words[i]].push_back(i);
        }
        return result;
    }
};

