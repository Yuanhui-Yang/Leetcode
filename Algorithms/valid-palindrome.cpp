// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.size(), i = 0, j = sz - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
            }
            else if (!isalnum(s[j])) {
                --j;
            }
            else if (tolower(s[i]) == tolower(s[j])) {
                ++i;
                --j;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main(void) {
	Solution solution;
	string s;
	bool answer, result;

	s = "A man, a plan, a canal: Panama";
	answer = true;
	result = solution.isPalindrome(s);
	assert(answer == result);

	s = "race a car";
	answer = false;
	result = solution.isPalindrome(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
