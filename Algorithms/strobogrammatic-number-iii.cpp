// 248. Strobogrammatic Number III
// https://leetcode.com/problems/strobogrammatic-number-iii/

/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
*/

class Solution {
public:
	int strobogrammaticInRange(string low, string high) {
		int a = low.size(), b = high.size();
		if (a > b) {
			return 0;
		}
		if (a == b and low > high) {
			return 0;
		}
		int result = 0;
		for (int i = a; i <= b; ++i) {
			result += g(low, high, "", i);
		}
		return result;
	}
private:
	bool f(const string & a, const string & b) {
		if (a.size() == b.size()) {
			return a < b;
		}
		return a.size() < b.size();
	}
	int g(const string & low, const string & high, string s, size_t n) {
		if (s.size() == n) {
			return (s.size() == 1 or (s.size() > 1 and s.front() != '0')) and !f(s, low) and !f(high, s);
		}
		int result = 0;
		if (s.empty() and (n & 1)) {
			result += g(low, high, "0", n);
			result += g(low, high, "1", n);
			result += g(low, high, "8", n);
		}
		else {
			result += g(low, high, "0" + s + "0", n);
			result += g(low, high, "1" + s + "1", n);
			result += g(low, high, "6" + s + "9", n);
			result += g(low, high, "8" + s + "8", n);
			result += g(low, high, "9" + s + "6", n);
		}
		return result;
	}
};