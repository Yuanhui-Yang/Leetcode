// 323. Number of Connected Components in an Undirected Graph
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countComponents(int n, vector<pair<int, int>>& edges) {
		vector<int> root(n);
		iota(begin(root), end(root), 0);
		for (const auto &i : edges) {
			int a = i.first, b = i.second;
			int ra = f(root, a), rb = f(root, b);
			if (ra != rb) {
				--n;
				root[ra] = rb;
			}
		}
		return n;
	}
private:
	int f(vector<int>& root, int i) {
		while (root[i] != i) {
			i = root[i] = root[root[i]];
		}
		return i;
	}
};

int main(void) {
	Solution solution;
	int n, answer, result;
	vector<pair<int, int>> edges;

	n = 5;
	edges = {{0, 1}, {1, 2}, {3, 4}};
	answer = 2;
	result = solution.countComponents(n, edges);
	assert(answer == result);

	n = 5;
	edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
	answer = 1;
	result = solution.countComponents(n, edges);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}