17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        string path;
        vector<string> A;
        A.push_back("abc");
        A.push_back("def");
        A.push_back("ghi");
        A.push_back("jkl");
        A.push_back("mno");
        A.push_back("pqrs");
        A.push_back("tuv");
        A.push_back("wxyz");
        f1(result, path, A, digits, 0);
        return result;
    }
private:
    void f1(vector<string> & result, string & path, vector<string> & A, string & digits, int begin) {
        int end = digits.size();
        if (begin == end) {
            result.push_back(path);
            return;
        }
        int id = digits[begin] - '2';
        for (const auto & i : A[id]) {
            path.push_back(i);
            f1(result, path, A, digits, begin + 1);
            path.pop_back();
        }
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