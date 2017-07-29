// 310. Minimum Height Trees
// https://leetcode.com/problems/minimum-height-trees/

/*
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

		0
		|
		1
	   / \
	  2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

	 0  1  2
	  \ | /
		3
		|
		4
		|
		5
return [3, 4]

Note:

(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (edges.empty()) {
			vector<int> result(n);
			iota(begin(result), end(result), 0);
			return result;
		}
		vector<list<int>> A(n);
		vector<int> B(n, 0);
		for (const auto & i : edges) {
			A[i.first].push_back(i.second);
			A[i.second].push_back(i.first);
			++B[i.first];
			++B[i.second];
		}
		vector<int> prev, curr;
		for (int i = 0; i < n; ++i) {
			if (B[i] == 1) {
				curr.push_back(i);
			}
		}
		while (!curr.empty()) {
			vector<int> next;
			for (const auto & i : curr) {
				for (const auto & j : A[i]) {
					if (--B[j] == 1) {
						next.push_back(j);
					}
				}
			}
			prev = curr;
			curr = next;
		}
		return prev;
	}
};