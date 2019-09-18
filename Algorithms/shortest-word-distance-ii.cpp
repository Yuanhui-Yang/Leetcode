/*
 * @lc app=leetcode id=244 lang=cpp
 *
 * [244] Shortest Word Distance II
 *
 * https://leetcode.com/problems/shortest-word-distance-ii/description/
 *
 * algorithms
 * Medium (48.92%)
 * Likes:    238
 * Dislikes: 87
 * Total Accepted:    55.2K
 * Total Submissions: 112.4K
 * Testcase Example:  '["WordDistance","shortest","shortest"]\n' +
  '[[["practice","makes","perfect","coding","makes"]],["coding","practice"],["makes","coding"]]'
 *
 * Design a class which receives a list of words in the constructor, and
 * implements a method that takes two words word1 and word2 and return the
 * shortest distance between these two words in the list. Your method will be
 * called repeatedly many times with different parameters. 
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
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are
 * both in the list.
 * 
 */
class WordDistance {
    unordered_map<string, vector<int>> A;
public:
    WordDistance(vector<string>& words) {
        A.clear();
        for (int sz = words.size(), i = 0; i < sz; ++i)
        {
            A[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& x = A[word1], &y = A[word2];
        int result = INT_MAX, sz1 = x.size(), sz2 = y.size(), i = 0, j = 0;
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
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */

