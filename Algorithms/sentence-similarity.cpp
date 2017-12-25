// 734. Sentence Similarity
// https://leetcode.com/problems/sentence-similarity/

/*
Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.

However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].
*/

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        unordered_map<string, unordered_set<string>> A = f1(pairs);
        int sz = words1.size(), i = 0;
        for (i = 0; i < sz; ++i) {
            string & s = words1[i], & t = words2[i];
            if (s == t) {
                continue;
            }
            else if (A.count(s) and A[s].count(t)) {
                continue;
            }
            else if (A.count(t) and A[t].count(s)) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
private:
    unordered_map<string, unordered_set<string>> f1(vector<pair<string, string>> & pairs) {
        unordered_map<string, unordered_set<string>> result;
        for (const auto & i : pairs) {
            result[i.first].insert(i.second);
            result[i.second].insert(i.first);
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<string> words1, words2;
    vector<pair<string, string>> pairs;
    bool result;
    
    words1 = {"great", "acting", "skills"};
    words2 = {"fine", "drama", "talent"};
    pairs = {{"great", "fine"}, {"drama", "acting"}, {"skills", "talent"}};
    result = solution.areSentencesSimilar(words1, words2, pairs);
    cout << boolalpha << result << '\n'; 
    
    return 0;
}