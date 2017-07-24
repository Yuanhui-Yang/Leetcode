// 401. Binary Watch
// https://leetcode.com/problems/binary-watch/

/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
*/

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> result;
		for (int i = 0; i <= num; ++i) {
			int j = num - i;
			vector<string> h = f(4, 0, 0, i, 11), m = f(6, 0, 0, j, 59);
			for (const auto & x : h) {
				for (const auto & y : m) {
					result.push_back(x + ":" + (y.size() == 1 ? "0" + y : y));
				}
			}
		}
		return result;
	}
private:
	vector<string> f(int sz, int index, int val, int num, int upper) {
		vector<string> result;
		if (val > upper) {
			return result;
		}
		if (num == 0) {
			result.push_back(to_string(val));
			return result;
		}
		for (; index < sz; ++index) {
			vector<string> v = f(sz, index + 1, val + (1 << index), num - 1, upper);
			result.insert(end(result), begin(v), end(v));
		}
		return result;
	}
};

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<int> A = {1, 2, 4, 8}, B = {1, 2, 4, 8, 16, 32};
		vector<string> result;
		for (int i = 0; i <= num; ++i) {
			int j = num - i;
			vector<string> h = f(A, 0, 0, i, 11), m = f(B, 0, 0, j, 59);
			for (const auto & x : h) {
				for (const auto & y : m) {
					result.push_back(x + ":" + (y.size() == 1 ? "0" + y : y));
				}
			}
		}
		return result;
	}
private:
	vector<string> f(const vector<int> & A, int index, int val, int num, int upper) {
		if (val > upper) {
			return {};
		}
		if (num == 0) {
			return {to_string(val)};
		}
		vector<string> result;
		for (int sz = A.size(), i = index; i < sz; ++i) {
			vector<string> v = f(A, i + 1, val + A[i], num - 1, upper);
			result.insert(end(result), begin(v), end(v));
		}
		return result;
	}
};