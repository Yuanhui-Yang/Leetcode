// 526. Beautiful Arrangement
// https://leetcode.com/problems/beautiful-arrangement/
#include <iostream>
#include <cassert>
#include <cctype>
using namespace std;

class Solution {
public:
	int countArrangement(int N) {
		int result = 0;
		for (int i = 1; i <= N; i++) {

		}
		return result;
	}
};
int main(void) {
	Solution solution;
	int N = 0;
	int result = 0;
	int answer = 0;

	N = 2;
	result = solution.countArrangement(N);
	answer = 2;
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}