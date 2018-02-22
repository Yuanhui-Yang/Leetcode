134. Gas Station
https://leetcode.com/problems/gas-station/

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size(), i = 0;
        while (i < sz) {
            int sum = 0, j = 0;
            while (j < sz and sum >= 0) {
                int k = i + j;
                k %= sz;
                sum += gas[k] - cost[k];
                ++j;
            }
            if (sum < 0) {
                i += j;
            }
            else {
                return i;
            }
        }
        return -1;
    }
};

int main(void) {
    Solution solution;
    vector<int> gas, cost;
    int result;

    gas = {5};
    cost = {4};
    result = solution.canCompleteCircuit(gas, cost);
    cout << result << '\n';

    gas = {4};
    cost = {5};
    result = solution.canCompleteCircuit(gas, cost);
    cout << result << '\n';

    gas = {1, 2};
    cost = {2, 1};
    result = solution.canCompleteCircuit(gas, cost);
    cout << result << '\n';

    return 0;
}