// 524. Longest Word in Dictionary through Deleting
// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		sort(begin(d), end(d), Comp());
		int sz = d.size(), i = 0;
		while (i < sz and !f(d[i], s)) {
			++i;
		}
		return i == sz ? "" : d[i];
	}
private:
	struct Comp {
		bool operator() (const string & a, const string & b) {
			if (a.size() == b.size()) {
				return a < b;
			}
			return a.size() > b.size();
		}
	};
	bool f(const string & shortStr, const string & longStr) {
		int P = shortStr.size(), Q = longStr.size(), i = 0, j = 0;
		while (i < P and j < Q) {
			if (shortStr[i] == longStr[j]) {
				++i;
				++j;
			}
			else {
				++j;
			}
		}
		return i == P;
	}
};