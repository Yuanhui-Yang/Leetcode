753. Cracking the Safe
https://leetcode.com/problems/cracking-the-safe/
There is a box protected by a password. The password is n digits, where each letter can be one of the first k digits 0, 1, ..., k-1.

You can keep inputting the password, the password will automatically be matched against the last n digits entered.

For example, assuming the password is "345", I can open it when I type "012345", but I enter a total of 6 digits.

Please return any string of minimum length that is guaranteed to open the box after the entire string is inputted.

Example 1:
Input: n = 1, k = 2
Output: "01"
Note: "10" will be accepted too.
Example 2:
Input: n = 2, k = 2
Output: "00110"
Note: "01100", "10011", "11001" will be accepted too.
Note:
n will be in the range [1, 4].
k will be in the range [1, 10].
k^n will be at most 4096.

#include <iostream>
#include <cmath>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        string result(n, '0');
        unordered_set<string> A;
        A.insert(result);
        f1(result, A, pow(k, n), n, k);
        return result;
    }
private:
    bool f1(string & result, unordered_set<string> & A, const size_t upper, const int n, const int k) {
        if (A.size() == upper) {
            return true;
        }
        for (int i = 0; i < k; ++i) {
            char ch = '0' + i;
            result.push_back(ch);
            string password = result.substr(result.size() - n);
            if (!A.count(password)) {
                A.insert(password);
                if (f1(result, A, upper, n, k)) {
                    return true;
                }
                A.erase(password);
            }
            result.pop_back();
        }
        return false;
    }
};

int main(void) {
    Solution solution;
    int n, k;
    string result;
    
    n = 1;
    k = 2;
    result = solution.crackSafe(n, k);
    cout << result << '\n';

    n = 2;
    k = 2;
    result = solution.crackSafe(n, k);
    cout << result << '\n';
    
    return 0;
}