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
		vector<string> result;
		string s;
		f(result, s, n);
		return result;
	}
private:
	void f(vector<string> & result, string & s, int n) {
		char a[3] = {'0', '1', '8'}, b[5] = {'0', '1', '6', '8', '9'};
		if (s.size() == n / 2) {
			string t(s);
			reverse(begin(t), end(t));
			for (auto & i : t) {
				if (i == '6') {
					i = '9';
					continue;
				}
				if (i == '9') {
					i = '6';
					continue;
				}
			}
			if (n & 1) {
				for (int i = 0; i < 3; ++i) {
					s.push_back(a[i]);
					result.push_back(s + t);
					s.pop_back();
				}
			}
			else {
				result.push_back(s + t);
			}
		}
		else {
			for (int i = s.empty(); i < 5; ++i) {
				s.push_back(b[i]);
				f(result, s, n);
				s.pop_back();
			}
		}
	}
};