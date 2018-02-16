734. Sentence Similarity
https://leetcode.com/problems/sentence-similarity/

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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        unordered_map<string, int> A = f1(pairs);
        vector<unordered_set<int>> B = f2(A, pairs);
        return f3(A, B, words1, words2);
    }
private:
    unordered_map<string, int> f1(vector<pair<string, string>> & pairs) {
        unordered_map<string, int> result;
        int cnt = 0;
        for (const auto & i : pairs) {
            const string & a = i.first, & b = i.second;
            if (!result.count(a)) {
                result[a] = cnt++;
            }
            if (!result.count(b)) {
                result[b] = cnt++;
            }
        }
        return result;
    }
    vector<unordered_set<int>> f2(unordered_map<string, int> & A, vector<pair<string, string>> & pairs) {
        vector<unordered_set<int>> result(A.size());
        for (const auto & i : pairs) {
            const string & a = i.first, & b = i.second;
            int x = A[a], y = A[b];
            if (x != y) {
                result[x].insert(y);
            }
        }
        return result;
    }
    bool f3(unordered_map<string, int> & A, vector<unordered_set<int>> & B, vector<string>& words1, vector<string>& words2) {
        int sz = min(words1.size(), words2.size());
        for (int i = 0; i < sz; ++i) {
            string & a = words1[i], & b = words2[i];
            if (a != b) {
                if (!A.count(a) or !A.count(b)) {
                    return false;
                }
                int x = A[a], y = A[b];
                if (x != y) {
                    if (!B[x].count(y) and !B[y].count(x)) {
                        return false;
                    }
                }
            }
        }
        return true;
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