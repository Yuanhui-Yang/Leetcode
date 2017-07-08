// 165. Compare Version Numbers
// https://leetcode.com/problems/compare-version-numbers/

/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

class Solution {
public:
	int compareVersion(string version1, string version2) {
		if (version1 == version2) {
			return 0;
		}
		vector<int> x, y;
		int m = version1.size(), n = version2.size(), i = 0, base = 10;
		while (i < m) {
			x.push_back(0);
			while (i < m and version1[i] != '.') {
				x.back() = base * x.back() + version1[i] - '0';
				++i;
			}
			++i;
		}
		i = 0;
		while (i < n) {
			y.push_back(0);
			while (i < n and version2[i] != '.') {
				y.back() = base * y.back() + version2[i] - '0';
				++i;
			}
			++i;
		}
		while (!x.empty() and !x.back()) {
			x.pop_back();
		}
		while (!y.empty() and !y.back()) {
			y.pop_back();
		}
		return x == y ? 0 : x < y ? -1 : 1;
	}
};