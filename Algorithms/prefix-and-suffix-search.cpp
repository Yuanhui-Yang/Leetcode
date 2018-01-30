745. Prefix and Suffix Search
https://leetcode.com/problems/prefix-and-suffix-search/

Given many words, words[i] has weight i.

Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.

Examples:
Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1
Note:
words has length in range [1, 15000].
For each test case, up to words.length queries WordFilter.f may be made.
words[i] has length in range [1, 10].
prefix, suffix have lengths in range [0, 10].
words[i] and prefix, suffix queries consist of lowercase letters only.

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    vector<int> weight;
    array<Node *, 26> next;
    Node() {
        this->weight.clear();
        this->next.fill(NULL);
    }
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        front = new Node();
        f1(front, words);
        back = new Node();
        for (auto & word : words) {
            reverse(word.begin(), word.end());
        }
        f1(back, words);
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        vector<int> a = f3(front, prefix), b = f3(back, suffix);
        int sz1 = a.size(), sz2 = b.size(), i = sz1 - 1, j = sz2 - 1;
        while (i >= 0 and j >= 0) {
            if (a[i] == b[j]) {
                return a[i];
            }
            else if (a[i] > b[j]) {
                --i;
            }
            else {
                --j;
            }
        }
        return -1;
    }
private:
    Node * front = NULL, * back = NULL;
    void f1(Node * root, vector<string> & words) {
        int sz = words.size();
        for (int i = 0; i < sz; ++i) {
            f2(root, words[i], i);
        }
    }    
    void f2(Node * root, string & word, int weight) {
        if (!root) {
            return;
        }
        root->weight.push_back(weight);
        for (const auto & i : word) {
            int id = i - 'a';
            if (!root->next[id]) {
                root->next[id] = new Node();
            }
            root = root->next[id];
            root->weight.push_back(weight);
        }
        
    }
    vector<int> f3(Node * root, string prefix) {
        if (!root) {
            return {};
        }
        for (const auto & i : prefix) {
            int id = i - 'a';
            root = root->next[id];
            if (!root) {
                return {};
            }
        }
        return root->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */

int main(void) {
    vector<string> words;
    int result;
    
    words = {"apple"};
    WordFilter obj = WordFilter(words);
    string prefix, suffix;
    prefix = "a";
    suffix = "e";
    result = obj.f(prefix, suffix);
    cout << result << '\n';
    prefix = "b";
    suffix = "";
    result = obj.f(prefix, suffix);
    cout << result << '\n';
    
    return 0;
}