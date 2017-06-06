// 555. Split Concatenated Strings
// https://leetcode.com/problems/split-concatenated-strings/

/*
Given a list of strings, you could concatenate these strings together into a loop, where for each string you could choose to reverse it or not. Among all the possible loops, you need to find the lexicographically biggest string after cutting the loop, which will make the looped string into a regular one.

Specifically, to find the lexicographically biggest string, you need to experience two phases:

Concatenate all the strings into a loop, where you can reverse some strings or not and connect them in the same order as given.
Cut and make one breakpoint in any place of the loop, which will make the looped string into a regular one starting from the character at the cutpoint.
And your job is to find the lexicographically biggest one among all the possible regular strings.

Example:
Input: "abc", "xyz"
Output: "zyxcba"
Explanation: You can get the looped string "-abcxyz-", "-abczyx-", "-cbaxyz-", "-cbazyx-", 
where '-' represents the looped status. 
The answer string came from the fourth looped one, 
where you could cut from the middle character 'a' and get "zyxcba".
Note:
The input strings will only contain lowercase letters.
The total length of all the strings will not over 1,000.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string splitLoopedString(vector<string>& strs) {
		vector<string> reverse_strs, v;
		for (const auto &s : strs) {
			string t(s);
			reverse(begin(t), end(t));
			reverse_strs.push_back(t);
			v.push_back(max(s, t));
		}
		string result = accumulate(begin(v), end(v), string(""));
		for (int i = 0, n = strs.size(); i < n; ++i) {
			const string &s = strs[i] , &t = reverse_strs[i];
			string x = accumulate(next(begin(v), i + 1), end(v), string("")) + accumulate(begin(v), next(begin(v), i), string(""));
			for (int j = 0, l = s.size(); j < l; ++j) {
				string a = s.substr(j) + x + s.substr(0, j), b = t.substr(j) + x + t.substr(0, j);
				result = max(result, max(a, b));
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> strs;
	string answer, result;

	strs = {"lc", "evol", "cdy"};
	answer = "ylclovecd";
	result = solution.splitLoopedString(strs);
	assert(answer == result);

	strs = {"a", "b", "c"};
	answer = "cab";
	result = solution.splitLoopedString(strs);
	assert(answer == result);

	strs = {"awef", "eawf", "zdaeff", "awefzewaf", "awefzewaf"};
	answer = "zfewafewafwaezdaefffawezfewafawe";
	result = solution.splitLoopedString(strs);
	assert(answer == result);

	strs = {"abc", "xyz"};
	answer = "zyxcba";
	result = solution.splitLoopedString(strs);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}