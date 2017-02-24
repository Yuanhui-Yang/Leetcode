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

	}
};
int main(void) {
	Solution solution;
	vector<int> machines;
	int result = 0;
	int answer = 0;

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