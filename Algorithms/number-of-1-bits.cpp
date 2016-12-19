// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/
#include <iostream>
#include <cassert>
#include <bitset>
using namespace std;
class Solution {
public:
	int hammingWeight(uint32_t n) {
		bitset<32> val(n);
		return val.count();
	}
};
int main(void) {
	Solution solution;
	assert(3 == solution.hammingWeight(0b00000000000000000000000000001011));
	cout << "\nPassed All\n";
	return 0;
}