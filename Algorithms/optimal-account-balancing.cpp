// 465. Optimal Account Balancing
// https://leetcode.com/problems/optimal-account-balancing/
#include <iostream>
#include <cassert>
#include <climits>
#include <vector>
#include <unordered_map>
using namespace std;
// BEGIN: http://www.mathmeth.com/tom/files/settling-debts.pdf
// BEGIN: http://www.cnblogs.com/grandyang/p/6108158.html
class Solution {
public:
	int minTransfers(vector<vector<int>>& transactions) {
		unordered_map<int, int> debts;
		for (const auto &transaction : transactions) {
			debts[transaction[0]] += transaction[2];
			debts[transaction[1]] -= transaction[2];
		}
		vector<int> OPT;
		for (const auto &debt : debts) {
			if (debt.second) {
				OPT.push_back(debt.second);
			}
		}
		return minTransfers(0, 0, OPT);
	}
private:
	int minTransfers(size_t current, int depth, vector<int>& OPT) {
		while (current < OPT.size() && !OPT[current]) {
			current++;
		}
		if (current == OPT.size()) {
			return depth;
		}
		int result = 0;
		for (size_t next = current + 1; next < OPT.size(); next++) {
			if (OPT[next] && ((OPT[current] < 0) ^ (OPT[next] < 0))) {
				OPT[next] += OPT[current];
				if (!result) result = minTransfers(current + 1, depth + 1, OPT);
				else result = min(result, minTransfers(current + 1, depth + 1, OPT));
				OPT[next] -= OPT[current];
			}
		}
		return result;
	}
};
// END: http://www.cnblogs.com/grandyang/p/6108158.html
// END: http://www.mathmeth.com/tom/files/settling-debts.pdf
int main(void) {
	Solution solution;
	vector<vector<int>> transactions;
	int result = 0;

	transactions = {{0, 1, 10}, {2, 0, 5}};
	result = solution.minTransfers(transactions);
	assert(2 == result);

	transactions = {{0, 1, 10}, {1, 0, 1}, {1, 2, 5}, {2, 0, 5}};
	result = solution.minTransfers(transactions);
	assert(1 == result);

	transactions = {{2, 0, 5}, {3, 4, 4}};
	result = solution.minTransfers(transactions);
	assert(2 == result);

	cout << "\nPassed All\n";
	return 0;
}