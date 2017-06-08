// 461. Hamming Distance
// https://leetcode.com/problems/hamming-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		return bitset<32>(x ^ y).count();
	}
};

int main(void) {
	Solution solution;
	int x, y, answer, result;

	x = 1;
	y = 4;
	answer = 2;
	result = solution.hammingDistance(x, y);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}