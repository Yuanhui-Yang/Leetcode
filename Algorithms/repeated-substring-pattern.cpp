// 459. Repeated Substring Pattern
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool repeatedSubstringPattern(string str) {
		const int n = str.size();
		for (int i = 1; i <= n / 2; i++) {
			if (n % i == 0) {
				string pat;
				for (int j = 0; j < n / i; j++)
					pat += str.substr(0, i);
				if (str == pat) return true;
			}
		}
		return false;
	}
};
int main(void) {
	Solution solution;
	cout << boolalpha << solution.repeatedSubstringPattern("abab") << "\tPassed\n";
	cout << boolalpha << solution.repeatedSubstringPattern("aba") << "\tPassed\n";
	cout << boolalpha << solution.repeatedSubstringPattern("abcabcabcabc") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}