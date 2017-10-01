// 273. Integer to English Words
// https://leetcode.com/problems/integer-to-english-words/

/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

#include <iostream>
#include <array>
#include <string>

using namespace std;

class Solution {
public:
	string numberToWords(int num) {
		int ten = 10, hundred = 1e2, thousand = 1e3, million = 1e6, billion = 1e9;
		array<string, 21> A({"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"});
		if (num <= 20) {
			return A[num];
		}
		array<string, 10> B({"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"});
		if (num < hundred) {
			return num % ten == 0 ? B[num / ten] : B[num / ten] + " " + numberToWords(num % ten); 
		}
		if (num < thousand) {
			return num % hundred == 0 ? numberToWords(num / hundred) + " Hundred" : numberToWords(num / hundred) + " Hundred " + numberToWords(num % hundred);
		}
		if (num < million) {
			return num % thousand == 0 ? numberToWords(num / thousand) + " Thousand" : numberToWords(num / thousand) + " Thousand " + numberToWords(num % thousand);
		}
		if (num < billion) {
			return num % million == 0 ? numberToWords(num / million) + " Million" : numberToWords(num / million) + " Million " + numberToWords(num % million);
		}
		return num % billion == 0 ? numberToWords(num / billion) + " Billion" : numberToWords(num / billion) + " Billion " + numberToWords(num % billion);
	}
};

int main(void) {
	Solution solution;
	int num;
	string result;

	num = 30;
	result = solution.numberToWords(num);
	cout << result << '\n';

	num = 123;
	result = solution.numberToWords(num);
	cout << result << '\n';

	num = 12345;
	result = solution.numberToWords(num);
	cout << result << '\n';

	num = 1234567;
	result = solution.numberToWords(num);
	cout << result << '\n';

	return 0;
}

#include <iostream>
#include <array>
#include <string>

using namespace std;

class Solution {
public:
	string numberToWords(int num) {
		array<string, 21> A({"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"});
		if (num <= 20) {
			return A[num];
		}
		array<string, 10> B({"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"});
		if (num < 100) {
			return num % 10 == 0 ? B[num / 10] : B[num / 10] + " " + numberToWords(num % 10); 
		}
		if (num < 1000) {
			return num % 100 == 0 ? numberToWords(num / 100) + " Hundred" : numberToWords(num / 100) + " Hundred " + numberToWords(num % 100);
		}
		if (num < 1000000) {
			return num % 1000 == 0 ? numberToWords(num / 1000) + " Thousand" : numberToWords(num / 1000) + " Thousand " + numberToWords(num % 1000);
		}
		if (num < 1000000000) {
			return num % 1000000 == 0 ? numberToWords(num / 1000000) + " Million" : numberToWords(num / 1000000) + " Million " + numberToWords(num % 1000000);
		}
		return num % 1000000000 == 0 ? numberToWords(num / 1000000000) + " Billion" : numberToWords(num / 1000000000) + " Billion " + numberToWords(num % 1000000000);
	}
};

int main(void) {
	Solution solution;
	int num;
	string result;

	num = 30;
	result = solution.numberToWords(num);
	cout << result << '\n';

	num = 123;
	result = solution.numberToWords(num);
	cout << result << '\n';

	num = 12345;
	result = solution.numberToWords(num);
	cout << result << '\n';

	num = 1234567;
	result = solution.numberToWords(num);
	cout << result << '\n';

	return 0;
}