// 365. Water and Jug Problem
// https://leetcode.com/problems/water-and-jug-problem/
#include <iostream>
#include <cassert>
using namespace std;
// BEGIN: https://www.hrwhisper.me/leetcode-water-jug-problem/
// BEGIN: https://en.wikipedia.org/wiki/Euclidean_algorithm
class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		int w = gcd(x , y);
		if (w == 0) return z == 0;
		return x + y >= z && z % w == 0;
	}
private:
	// int gcd(int a, int b) {
	// 	return b == 0 ? a : gcd(b, a % b);
	// }
	int gcd(int a, int b) {
		while (b) {
			int tmp = a % b;
			a = b;
			b = tmp;
		}
		return a;
	}
};
// END: https://en.wikipedia.org/wiki/Euclidean_algorithm
// END: https://www.hrwhisper.me/leetcode-water-jug-problem/
int main(void) {
	Solution solution;
	assert(true == solution.canMeasureWater(3, 5, 4));
	assert(false == solution.canMeasureWater(2, 6, 5));
	assert(true == solution.canMeasureWater(0, 0, 0));
	cout << "\nPassed All\n";
	return 0;
}