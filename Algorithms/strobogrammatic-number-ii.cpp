// 247. Strobogrammatic Number II
// https://leetcode.com/problems/strobogrammatic-number-ii/

/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/

class Solution {
public:
vector<string> findStrobogrammatic(int n) {
unordered_map<char, char> h;
h['0'] = '0';
h['1'] = '1';
h['6'] = '9';
h['8'] = '8';
h['9'] = '6';
vector<string> result;
string s(n, ' ');
f(result, s, h, n, 0);
return result;
}
private:
	void f(vector<string>& result, string& s, unordered_map<char, char>& h, int n, int i) {
		if (i == n / 2) {
			if (n & 1) {
				s[i] = '0';
				result.push_back(s);
				s[i] = '1';
				result.push_back(s);
				s[i] = '8';
				result.push_back(s);
			}
			else {
				result.push_back(s);
			}
			return;
		}
		for (const auto &c : h) {
			if (i == 0 and c.first == '0') {
				continue;
			}
			char d = s[i], e = s[n - 1 - i];
			s[i] = c.first;
			s[n - 1 - i] = c.second;
			f(result, s, h, n, i + 1);
			s[i] = d;
			s[n - 1 - i] = e;
		}
	}
};