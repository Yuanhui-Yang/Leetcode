// 134. Gas Station
// https://leetcode.com/problems/gas-station/

/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size(), i = 0;
		while (i < n) {
			int b = 0, j = 0;
			for (j = 0;  j < n; ++j) {
				int k = i + j;
				k %= n;
				b += gas[k] - cost[k];
				if (b < 0) {
					break;
				}
			}
			if (j >= n) {
				return i;
			}
			i += j + 1;
		}
		return -1;
	}
};

int main(void) {
	Solution solution;
	vector<int> gas, cost;
	int answer, result;

	gas = {5};
	cost = {4};
	answer = 0;
	result = solution.canCompleteCircuit(gas, cost);
	assert(answer == result);

	gas = {4};
	cost = {5};
	answer = -1;
	result = solution.canCompleteCircuit(gas, cost);
	assert(answer == result);

	gas = {1, 2};
	cost = {2, 1};
	answer = 1;
	result = solution.canCompleteCircuit(gas, cost);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}