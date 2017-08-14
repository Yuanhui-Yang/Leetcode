// 306. Additive Number
// https://leetcode.com/problems/additive-number/

/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
*/

class Solution {
public:
	bool isAdditiveNumber(string num) {
		int sz = num.size();
		for (int i = 1; i <= sz / 2; ++i) {
			if (num[0] == '0' and i > 1) {
				return false;
			}
			for (int j = 1; i + j < sz; ++j) {
				if (num[i] == '0' and j > 1) {
					break;
				}
				if (f(num.substr(0, i), num.substr(i, j), i + j, num)) {
					return true;
				}
			}
		}
		return false;
	}
private:
	bool f(string a, string b, int id, string num) {
		int sz = num.size();
		if (id == sz) {
			return true;
		}
		if (id > sz) {
			return false;
		}
		int m = a.size(), n = b.size(), l = max(m, n) + 1, i = m - 1, j = n - 1, k = l - 1, carry = 0, base = 10;
		string c(l, '0');
		while (i >= 0 or j >= 0 or carry > 0) {
			int x = i >= 0 ? a[i--] - '0' : 0;
			int y = j >= 0 ? b[j--] - '0' : 0;
			int z = x + y + carry;
			carry = z / base;
			z %= base;
			c[k--] += z;
		}
		while (!c.empty() and c.front() == '0') {
			c.erase(begin(c));
		}
		if (c.empty()) {
			c = "0";
		}
		return id + c.size() <= num.size() and c == num.substr(id, c.size()) and f(b, c, id + c.size(), num);
	}
};