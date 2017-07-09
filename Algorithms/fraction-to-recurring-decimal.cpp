// 166. Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/

/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

class Solution {
public:
	string fractionToDecimal(long long numerator, long long denominator) {
		if (numerator == 0) {
			return "0";
		}
		if (numerator < 0 and denominator > 0) {
			return "-" + fractionToDecimal(-numerator, denominator);
		}
		if (numerator > 0 and denominator < 0) {
			return "-" + fractionToDecimal(numerator, -denominator);
		}
		if (numerator < 0 and denominator < 0) {
			return fractionToDecimal(-numerator, -denominator);
		}
		if (numerator < 0 and denominator == 0) {
			return to_string(INT_MIN);
		}
		if (numerator > 0 and denominator == 0) {
			return to_string(INT_MAX);
		}
		string result;
		result.append(to_string(numerator / denominator));
		numerator %= denominator;
		if (!numerator) {
			return result;
		}
		result.push_back('.');
		long long id = result.size(), base = 10;
		unordered_map<long long, long long> dict;
		do {
			dict[numerator] = id++;
			numerator *= base;
			result.push_back('0' + numerator / denominator);
			numerator %= denominator;
		} while (numerator and !dict.count(numerator));
		if (dict.count(numerator)) {
			result.insert(next(begin(result), dict[numerator]), '(');
			result.push_back(')');
		}
		return result;
	}
};