// 726. Number of Atoms
// https://leetcode.com/problems/number-of-atoms/

/*
Given a chemical formula (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

Example 1:
Input: 
formula = "H2O"
Output: "H2O"
Explanation: 
The count of elements are {'H': 2, 'O': 1}.
Example 2:
Input: 
formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: 
The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:
Input: 
formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: 
The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
Note:

All atom names consist of lowercase letters, except for the first character which is uppercase.
The length of formula will be in the range [1, 1000].
formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        vector<pair<string, int>> A, B;
        int sz = formula.size(), i = 0, num = 0;
        char ch;
        while (i < sz) {
            ch = formula[i];
            if (ch == '(') {
                A.push_back({"(", 1});
                ++i;
            }
            else if (ch == ')') {
                if (!A.empty() and A.back().first == ")") {
                    A.pop_back();
                    B.clear();
                    while (!A.empty() and A.back().first != "(") {
                        B.push_back(A.back());
                        A.pop_back();
                    }
                    if (!A.empty() and A.back().first == "(") {
                        A.pop_back();
                    }
                    while (!B.empty()) {
                        A.push_back(B.back());
                        B.pop_back();
                    }
                }
                A.push_back({")", 1});
                ++i;
            }
            else if (isdigit(ch)) {
                num = 0;
                while (i < sz and isdigit(formula[i])) {
                    num = 10 * num + (formula[i] - '0');
                    ++i;
                }
                if (A.back().first == ")") {
                    A.pop_back();
                    B.clear();
                    while (!A.empty() and A.back().first != "(") {
                        B.push_back(A.back());
                        A.pop_back();
                    }
                    if (!A.empty() and A.back().first == "(") {
                        A.pop_back();
                        while (!B.empty()) {
                            B.back().second *= num;
                            A.push_back(B.back());
                            B.pop_back();
                        }
                    }
                }
                else {
                    A.back().second *= num;
                }
            }
            else if (isupper(ch)) {
                A.push_back({formula.substr(i, 1), 1});
                ++i;
            }
            else if (islower(ch)) {
                A.back().first.push_back(ch);
                ++i;
            }
            else {
                ++i;
            }
        }
        return f1(A);
    }
private:
    string f1(vector<pair<string, int>> & A) {
        string result;
        map<string, int> B;
        for (const auto & i : A) {
            B[i.first] += i.second;
        }
        for (const auto & i : B) {
            result.append(i.first);
            if (i.second > 1) {
                result.append(to_string(i.second));
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string formula, result;
    
    formula = "H2O";
    result = solution.countOfAtoms(formula);
    cout << result << '\n';

    formula = "Mg(OH)2";
    result = solution.countOfAtoms(formula);
    cout << result << '\n';

    formula = "K4(ON(SO3)2)2";
    result = solution.countOfAtoms(formula);
    cout << result << '\n';

    return 0;
}