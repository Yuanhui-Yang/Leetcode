// 737. Sentence Similarity II
// https://leetcode.com/problems/sentence-similarity-ii/

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
        vector<int> B = f2(A, pairs);
        int sz = words1.size(), i = 0, a, b;
        for (i = 0; i < sz; ++i) {
            string & s = words1[i], & t = words2[i];
            if (s == t) {
                continue;
            }
            if (!A.count(s) or !A.count(t)) {
                return false;
            }
            a = A[s];
            a = f3(B, a);
            b = A[t];
            b = f3(B, b);
            if (a != b) {
                return false;
            }
        }
        return true;
    }
private:
    unordered_map<string, int> f1(vector<pair<string, string>> & pairs) {
        unordered_map<string, int> result;
        int n = 0;
        for (const auto & p : pairs) {
            if (!result.count(p.first)) {
                result[p.first] = n++;
            }
            if (!result.count(p.second)) {
                result[p.second] = n++;
            }
        }
        return result;
    }
    vector<int> f2(unordered_map<string, int> & A, vector<pair<string, string>> & pairs) {
        int sz = A.size(), a, b;
        vector<int> result(sz, 0);
        iota(result.begin(), result.end(), 0);
        for (const auto & p : pairs) {
            a = A[p.first];
            a = f3(result, a);
            b = A[p.second];
            b = f3(result, b);
            if (a != b) {
                result[a] = b;
            }
        }
        return result;
    }
    int f3(vector<int> & B, int root) {
        return root == B[root] ? root : B[root] = f3(B, B[root]);
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
