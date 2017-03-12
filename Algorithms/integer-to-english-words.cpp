// 273. Integer to English Words
// https://leetcode.com/problems/integer-to-english-words/

// Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

// For example,
// 123 -> "One Hundred Twenty Three"
// 12345 -> "Twelve Thousand Three Hundred Forty Five"
// 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// Hint:

// Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
// Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
// There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)

#include <iostream> // std::cout; std::cin
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // memset
#include <algorithm> // max; min; min_element; max_element; minmax_element; next_permutation; prev_permutation; nth_element; sort; swap; lower_bound; upper_bound; reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::string::npos
#include <list>
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	string numberToWords(int num) {
		if (num < 0) {
			return "";
		}
		vector<string> OPT1 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		vector<string> OPT2 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
		if (num < 10) {
			return OPT1.at(num);
		}
		if (num < 100) {
			if (num < 20) {
				return OPT1.at(num);
			}
			if (num % 10 == 0) {
				return OPT2.at(num / 10);
			}
			return OPT2.at(num / 10) + ' ' + OPT1.at(num % 10);
		}
		if (num < 1000) {
			if (num % 100 == 0) {
				return numberToWords(num / 100) + ' ' + "Hundred";
			}
			return numberToWords(num / 100) + ' ' + "Hundred" + ' ' + numberToWords(num % 100);
		}
		if (num < 1000000) {
			if (num % 1000 == 0) {
				return numberToWords(num / 1000) + ' ' + "Thousand";
			}
			return numberToWords(num / 1000) + ' ' + "Thousand" + ' ' + numberToWords(num % 1000);
		}
		if (num < 1000000000) {
			if (num % 1000000 == 0) {
				return numberToWords(num / 1000000) + ' ' + "Million";
			}
			return numberToWords(num / 1000000) + ' ' + "Million" + ' ' + numberToWords(num % 1000000);
		}
		if (num % 1000000000 == 0) {
			return numberToWords(num / 1000000000) + ' ' + "Billion";
		}
		return numberToWords(num / 1000000000) + ' ' + "Billion" + ' ' + numberToWords(num % 1000000000);
	}
};

// class Solution {
// public:
// 	string numberToWords(int num) {
// 		if (num < 0) {
// 			return "";
// 		}
// 		string s = to_string(num);
// 		size_t n = s.size();
// 		string result;
// 		vector<string> OPT1 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
// 		vector<string> OPT2 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
// 		if (n == 1) {
// 			return OPT1.at(num);
// 		}
// 		if (n == 2) {
// 			if (num < 20) {
// 				return OPT1.at(num);
// 			}
// 			if (num % 10 == 0) {
// 				return OPT2.at(num / 10);
// 			}
// 			return OPT2.at(num / 10) + ' ' + OPT1.at(num % 10);
// 		}
// 		if (n == 3) {
// 			if (num % 100 == 0) {
// 				return numberToWords(num / 100) + ' ' + "Hundred";
// 			}
// 			return numberToWords(num / 100) + ' ' + "Hundred" + ' ' + numberToWords(num % 100);
// 		}
// 		if (n <= 6) {
// 			if (num % 1000 == 0) {
// 				return numberToWords(num / 1000) + ' ' + "Thousand";
// 			}
// 			return numberToWords(num / 1000) + ' ' + "Thousand" + ' ' + numberToWords(num % 1000);
// 		}
// 		if (n <= 9) {
// 			if (num % 1000000 == 0) {
// 				return numberToWords(num / 1000000) + ' ' + "Million";
// 			}
// 			return numberToWords(num / 1000000) + ' ' + "Million" + ' ' + numberToWords(num % 1000000);
// 		}
// 		if (n == 10) {
// 			if (num % 1000000000 == 0) {
// 				return numberToWords(num / 1000000000) + ' ' + "Billion";
// 			}
// 			return numberToWords(num / 1000000000) + ' ' + "Billion" + ' ' + numberToWords(num % 1000000000);
// 		}
// 		return result;
// 	}
// };

int main(void) {
	Solution solution;
	int num = 0;
	string result, answer;

	num = 1234567891;
	answer = "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One";
	result = solution.numberToWords(num);
	assert(answer == result);

	num = 100000;
	answer = "One Hundred Thousand";
	result = solution.numberToWords(num);
	assert(answer == result);

	num = 123;
	answer = "One Hundred Twenty Three";
	result = solution.numberToWords(num);
	assert(answer == result);

	num = 12345;
	answer = "Twelve Thousand Three Hundred Forty Five";
	result = solution.numberToWords(num);
	assert(answer == result);

	num = 1234567;
	answer = "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";
	result = solution.numberToWords(num);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}