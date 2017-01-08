// 476. Number Complement
// https://leetcode.com/problems/number-complement/
#include <iostream>
#include <cassert>
using namespace std;
class Solution {
public:
	int findComplement(int num) {
		int result = 0;
		for (size_t i = 0, j = 0; i < 8 * sizeof(int); i++) {
			int idx = 1 << (8 * sizeof(int) - i - 1);
			if (!j) {
				if (idx & num) j = 1;
				continue;
			}
			if (!(idx & num)) result += idx;
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	int result = 0;
	result = solution.findComplement(5);
	assert(2 == result);
	result = solution.findComplement(1);
	assert(0 == result);
	cout << "\nPassed All\n";
	return 0;
}