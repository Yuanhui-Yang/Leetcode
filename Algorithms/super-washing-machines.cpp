// 517. Super Washing Machines
// https://leetcode.com/problems/super-washing-machines/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int findMinMoves(vector<int>& machines) {
		const size_t machines_size = machines.size();
		if (machines_size <= 1) {
			return 0;
		}
		long long sum = 0;
		long long result = 0;
		for (auto &machine : machines) {
			sum += (long long)(machine);
			if (machine == 0) {
				machine = 1;
				result++;
			}
		}
		if (sum == 0) {
			return 0;
		}
		if (sum % machines_size) {
			return -1;
		}
		const long long target = sum / machines_size;
		for (const auto &machine : machines) {
			if (machine < target) {
				result += target - machine;
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> machines;
	int result = 0;
	int answer = 0;

	machines = {4, 0, 0, 4};
	answer = 2;
	result = solution.findMinMoves(machines);
	assert(answer == result);

	machines = {1, 0, 5};
	answer = 3;
	result = solution.findMinMoves(machines);
	assert(answer == result);

	machines = {0, 3, 0};
	answer = 2;
	result = solution.findMinMoves(machines);
	assert(answer == result);

	machines = {0, 2, 0};
	answer = -1;
	result = solution.findMinMoves(machines);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
