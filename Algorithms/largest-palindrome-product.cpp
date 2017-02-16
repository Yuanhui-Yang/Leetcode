// 479. Largest Palindrome Product
// https://leetcode.com/problems/largest-palindrome-product/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
class Solution {
public:
	int largestPalindrome(int n) {
		
	}
};
int main(void) {
	Solution solution;
	int n = 0;
	int result = 0;
	int answer = 0;

	n = 2;
	answer = 987;
	result = solution.largestPalindrome(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}