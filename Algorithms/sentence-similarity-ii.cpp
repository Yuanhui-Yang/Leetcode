737. Sentence Similarity II
https://leetcode.com/problems/sentence-similarity-ii/

Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.

Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

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
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        unordered_map<string, int> A = f1(pairs);
        vector<int> B(A.size());
        iota(B.begin(), B.end(), 0);
        f2(A, B, pairs);
        return f4(A, B, words1, words2);
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
    void f2(unordered_map<string, int> & A, vector<int> & B, vector<pair<string, string>> & pairs) {
        for (const auto & i : pairs) {
            const string a = i.first, & b = i.second;
            if (a != b) {
                int x = A[a], y = A[b];
                if (x != y) {
                    int p = f3(B, x), q = f3(B, y);
                    if (p != q) {
                        B[p] = q;
                    }
                }
            }
        }
    }
    int f3(vector<int> & B, int id) {
        return B[id] == id ? id : B[id] = f3(B, B[id]);
    }
    bool f4(unordered_map<string, int> & A, vector<int> & B, vector<string>& words1, vector<string>& words2) {
        if (words1.size() != words2.size()) {
            return false;
        }
        int sz = words1.size();
        for (int i = 0; i < sz; ++i) {
            const string a = words1[i], & b = words2[i];
            if (a != b) {
                if (!A.count(a) or !A.count(b)) {
                    return false;
                }
                int x = A[a], y = A[b];
                if (x != y) {
                    int p = f3(B, x), q = f3(B, y);
                    if (p != q) {
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
    pairs = {{"great", "good"}, {"fine", "good"}, {"drama", "acting"}, {"skills", "talent"}};
    result = solution.areSentencesSimilarTwo(words1, words2, pairs);
    cout << boolalpha << result << '\n';
    
    return 0;
}