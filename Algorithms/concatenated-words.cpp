472. Concatenated Words
https://leetcode.com/problems/concatenated-words/

Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Comp {
    bool operator () (string & a, string & b) {
        return a.size() < b.size();
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), Comp());
        vector<string> result;
        unordered_set<string> A;
        for (const auto & i : words) {
            if (!i.empty()) {
                if(f1(i, A)) {
                    result.push_back(i);
                } 
            }
            A.insert(i);
        }
        return result;
    }
private:
    bool f1(const string & s, const unordered_set<string> & A) {
        int sz = s.size();
        vector<int> B(sz + 1, false);
        B[sz] = true;
        for (int i = sz - 1; i >= 0; --i) {
            for (int j = 1; i + j <= sz; ++j) {
                int k = i + j;
                string t = s.substr(i, j);
                if (A.count(t)) {
                    B[i] = B[k];
                }
                if (B[i]) {
                    break;
                }
            }
        }
        return B[0];
    }
};

int main(void) {
    Solution solution;
    vector<string> words, result;
    
    words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    result = solution.findAllConcatenatedWordsInADict(words);
    for (const auto & i : words) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}