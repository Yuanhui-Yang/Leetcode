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

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	string splitLoopedString(vector<string>& strs) {
		vector<string> rstrs, A;
		string r, s, t, result;
		int sz = strs.size(), i, j, k;
		for (i = 0; i < sz; ++i) {
			r = strs[i];
			s = r;
			reverse(begin(r), end(r));
			rstrs.push_back(r);
			A.push_back(max(r, s));
		}
		for (i = 0; i < sz; ++i) {
			r = accumulate(next(begin(A), i + 1), end(A), string()) + accumulate(begin(A), next(begin(A), i), string());
			k = strs[i].size();
			for (j = 0; j < k; ++j) {
				s = strs[i].substr(j) + r + strs[i].substr(0, j);
				t = rstrs[i].substr(j) + r + rstrs[i].substr(0, j);
				result = max(result, max(s, t));
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> strs;
	string result;
	
	strs = {"abc", "xyz"};
	result = solution.splitLoopedString(strs);
	cout << result << '\n';

	strs = {"awef", "eawf", "zdaeff", "awefzewaf", "awefzewaf"};
	result = solution.splitLoopedString(strs);
	cout << result << '\n';    

	return 0;
}