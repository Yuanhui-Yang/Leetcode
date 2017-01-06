// 433. Minimum Genetic Mutation
// https://leetcode.com/problems/minimum-genetic-mutation/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		unordered_set<string> nodes;
		nodes.insert(start);
		for (const auto &i : bank) {
			if (i.size() == start.size()) {
				nodes.insert(i);
			}
		}
		if (!nodes.count(end)) return -1;
		unordered_map<string, unordered_set<string>> graph;
		for (const auto &i : nodes) {
			for (const auto &j : nodes) {
				if (i != j) {
					if (graph.count(i) && graph[i].count(j)) continue;
					if (graph.count(j) && graph[j].count(i)) {
						graph[i].insert(j);
						continue;
					}
					size_t cnt = 0;
					for (size_t k = 0; k < start.size(); k++) {
						cnt += i[k] != j[k];
					}
					if (cnt == 1) {
						graph[i].insert(j);
						graph[j].insert(i);
					}
				}
			}
		}
		unordered_set<string> visited;
		vector<string> stack;
		visited.insert(start);
		stack.push_back(start);
		unordered_map<string, int> distance;
		distance[start] = 0;
		while (!stack.empty()) {
			const string stack_back = stack.back();
			stack.pop_back();
			for (const auto &i : graph[stack_back]) {
				if (!visited.count(i)) {
					if (i == end) return distance[stack_back] + 1;
					visited.insert(i);
					stack.push_back(i);
					distance[i] = distance[stack_back] + 1;
				}
			}
		}
		return -1;
	}
};
int main(void) {
	Solution solution;
	string start, end;
	vector<string> bank;
	int result = 0;
	start = "AACCGGTT";
	end = "AACCGGTA";
	bank = {"AACCGGTA"};
	result = solution.minMutation(start, end, bank);
	assert(1 == result);
	start = "AACCGGTT";
	end = "AAACGGTA";
	bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
	result = solution.minMutation(start, end, bank);
	assert(2 == result);
	start = "AAAAACCC";
	end = "AACCCCCC";
	bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
	result = solution.minMutation(start, end, bank);
	assert(3 == result);
	start = "AAAACCCC";
	end = "CCCCCCCC";
	bank = {"AAAACCCA","AAACCCCA","AACCCCCA","AACCCCCC","ACCCCCCC","CCCCCCCC","AAACCCCC","AACCCCCC"};
	result = solution.minMutation(start, end, bank);
	assert(4 == result);
	cout << "\nPassed All\n";
	return 0;
}