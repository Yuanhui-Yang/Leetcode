17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        array<string, 10> A;
        A[0] = "";
        A[1] = "";
        A[2] = "abc";
        A[3] = "def";
        A[4] = "ghi";
        A[5] = "jkl";
        A[6] = "mno";
        A[7] = "pqrs";
        A[8] = "tuv";
        A[9] = "wxyz";
        for (const auto & ch : digits) {
            int id = ch - '0';
            vector<string> next;
            if (result.empty()) {
                for (const auto & c : A[id]) {
                    string s;
                    s.push_back(c);
                    next.push_back(s);
                }
            }
            else {
                for (auto & s : result) {
                    for (const auto & c : A[id]) {
                        s.push_back(c);
                        next.push_back(s);
                        s.pop_back();
                    }
                }
            }
            result = next;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string digits;
    vector<string> result;
    
    digits = "23";
    result = solution.letterCombinations(digits);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}
