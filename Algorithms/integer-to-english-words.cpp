273. Integer to English Words
https://leetcode.com/problems/integer-to-english-words/

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        A = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        B = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return f1(num);
    }
private:
    vector<string> A, B;
    string f1(int num) {
        string result;
        if (num < 20) {
            result = A[num]; 
        }
        else if (num < 100) {
            result = B[num / 10] + " " + f1(num % 10);
        }
        else if (num < 1000) {
            result = A[num / 100] + " Hundred " + f1(num % 100);
        }
        else if (num < 1000000) {
            result = f1(num / 1000) + " Thousand " + f1(num % 1000);
        }
        else if (num < 1000000000) {
            result = f1(num / 1000000) + " Million " + f1(num % 1000000);
        }
        else {
            result = f1(num / 1000000000) + " Billion " + f1(num % 1000000000);
        }
        while (!result.empty() and result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    int num;
    string result;

    num = 123;
    result = solution.numberToWords(num);
    cout << result << '\n';

    num = 12345;
    result = solution.numberToWords(num);
    cout << result << '\n';

    num = 1234567;
    result = solution.numberToWords(num);
    cout << result << '\n';

    return 0;
}
