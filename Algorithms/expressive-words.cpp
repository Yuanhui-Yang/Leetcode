809. Expressive Words
https://leetcode.com/problems/expressive-words/

Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or more, so "e" and "o" would be extended in the first example, and "i" would be extended in the second example.  As another example, the groups of "abbcccaaaa" would be "a", "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups of that string.

For some given string S, a query word is stretchy if it can be made to be equal to S by extending some groups.  Formally, we are allowed to repeatedly choose a group (as defined above) of characters c, and add some number of the same character c to it so that the length of the group is 3 or more.  Note that we cannot extend a group of size one like "h" to a group of size two like "hh" - all extensions must leave the group extended - ie., at least 3 characters long.

Given a list of query words, return the number of words that are stretchy. 

Example:
Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.
Notes:

0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int result = 0;
        for (const auto & i : words) {
            result += f1(S, i);
        }
        return result;
    }
private:
    int f1(const string & s, const string & p) {
        int sz1 = s.size(), sz2 = p.size(), i = 0, j = 0;
        while (i < sz1 and j < sz2 and s[i] == p[j]) {
            int x = 0, y = 0;
            while (i + 1 < sz1 and s[i] == s[i + 1]) {
                ++x;
                ++i;
            }
            while (j + 1 < sz2 and p[j] == p[j + 1]) {
                ++y;
                ++j;
            }
            if (x < y) {
                return false;
            }
            if (x > y and x < 2) {
                return false;
            }
            ++i;
            ++j;
        }
        return i == sz1 and j == sz2;
    }
};

int main(void) {
    Solution solution;
    string S;
    vector<string> words;
    int result;
    
    S = "heeellooo";
    words = {"hello", "hi", "helo"};
    result = solution.expressiveWords(S, words);
    cout << result << '\n';
    
    return 0;
}
