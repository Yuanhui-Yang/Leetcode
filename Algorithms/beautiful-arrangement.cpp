// 526. Beautiful Arrangement
// https://leetcode.com/problems/beautiful-arrangement/
#include <iostream>
#include <cassert>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// BEGIN: Time Limit Exceeded
class Solution {
public:
	int countArrangement(int N) {
		int result = 0;
		vector<int> OPT;
		for (int i = 1; i <= N; i++) {
			OPT.push_back(i);
		}
		do {
			bool x = true;
			for (int i = 0; x && i < N; i++) {
				if (OPT[i] % (i + 1) && (i + 1) % OPT[i]) {
					x = false;
				}
			}
			result += x;
		} while (next_permutation(begin(OPT), end(OPT)));
		return result;
	}
};
// END: Time Limit Exceeded

int main(void) {
	Solution solution;
	int N = 0;
	int result = 0;
	int answer = 0;

	N = 12;
	result = solution.countArrangement(N);
	answer = 4010;
	assert(answer == result);

	N = 2;
	result = solution.countArrangement(N);
	answer = 2;
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}