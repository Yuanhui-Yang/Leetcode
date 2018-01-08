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
        f1(result, "", num, 0, target, 0, 0);
        return result;
    }
private:
    void f1(vector<string> & result, string path, string & num, int begin, long target, long eval, long mul) {
        int end = num.size(), sz;
        long val;
        string s;
        if (begin == end) {
            if (target == eval) {
                result.push_back(path);
            }
            return;
        }
        for (int i = 1; i <= end - begin; ++i) {
            if (i > 1 and num[begin] == '0') {
                break;
            }
            s = num.substr(begin, i);
            val = stol(s);
            if (begin == 0) {
                f1(result, s, num, begin + i, target, val, val);
            }
            else {
                f1(result, path + "+" + s, num, begin + i, target, eval + val, val);
                f1(result, path + "-" + s, num, begin + i, target, eval - val, -val);
                f1(result, path + "*" + s, num, begin + i, target, eval - mul + mul * val, mul * val);
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