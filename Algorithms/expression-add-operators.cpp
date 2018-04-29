282. Expression Add Operators
https://leetcode.com/problems/expression-add-operators/

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        f1(result, num, 0, "", 0, 0, target);
        return result;
    }
private:
    void f1(vector<string> & result, string & num, int start, string s, long val, long mul, long target) {
        int sz = num.size();
        if (start >= sz) {
            if (val == target) {
                result.push_back(s);
            }
            return;
        }
        for (int len = 1; len <= sz - start; ++len) {
            if (num[start] == '0' and 2 <= len) {
                return;
            }
            string t = num.substr(start, len);
            long ele = stol(t);
            if (start == 0) {
                f1(result, num, start + len, t, val + ele, ele, target);
            }
            else {
                f1(result, num, start + len, s + "+" + t, val + ele, ele, target);
                f1(result, num, start + len, s + "-" + t, val - ele, -ele, target);
                f1(result, num, start + len, s + "*" + t, val - mul + mul * ele, mul * ele, target);   
            }
        }
    }
};

int main(void) {
    Solution solution;
    string num;
    int target;
    vector<string> result;
    
    num = "123";
    target = 6;
    result = solution.addOperators(num, target);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    num = "232";
    target = 8;
    result = solution.addOperators(num, target);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    num = "105";
    target = 5;
    result = solution.addOperators(num, target);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    num = "00";
    target = 0;
    result = solution.addOperators(num, target);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    num = "3456237490";
    target = 9191;
    result = solution.addOperators(num, target);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}
