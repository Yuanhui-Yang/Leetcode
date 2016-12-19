// 461. Hamming Distance
// https://leetcode.com/problems/hamming-distance/
#include <iostream>
#include <cassert>
#include <bitset>
using namespace std;
class Solution {
public:
	int hammingDistance(int x, int y) {
		bitset<32> a(x), b(y);
		int result = 0;
		for (int i = 0; i < 32; i++) result += a[i] != b[i];
		return result;
	}
};
int main(void) {
	Solution solution;
	assert(2 == solution.hammingDistance(1, 4));
	cout << "\nPassed All\n";
	return 0;
}