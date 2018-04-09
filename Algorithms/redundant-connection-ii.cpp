685. Redundant Connection II
https://leetcode.com/problems/redundant-connection-ii/

In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        cnt = edges.size();
        A.resize(cnt + 1);
        iota(A.begin(), A.end(), 0);
        B.resize(cnt + 1, 1);
        C.resize(cnt + 1, 0);
        vector<vector<int>> candidates;
        for (auto & edge : edges) {
            int from = edge[0], to = edge[1];
            if (C[to]) {
                candidates.push_back({C[to], to});
                candidates.push_back(edge);
                edge[0] = 0;
                edge[1] = 0;
            }
            else {
                C[to] = from;
            }
        }
        for (const auto & edge : edges) {
            int x = edge[0], y = edge[1];
            if (x > 0 and y > 0) {
                int a = find(x), b = find(y);
                if (a == b) {
                    if (candidates.empty()) {
                        return edge;
                    }
                    else {
                        return candidates[0];
                    }
                }
                unoin(a, b);   
            }
        }
        return candidates[1];
    }
private:
    int cnt;
    vector<int> A, B, C;
    int find(int id) {
        while (id != A[id]) {
            A[id] = A[A[id]];
            id = A[id];
        }
        return id;
    }
    void unoin(int x, int y) {
        int a = find(x), b = find(y);
        if (a == b) {
            return;
        }
        if (B[a] > B[b]) {
            swap(a, b);
        }
        A[a] = b;
        B[b] += B[a];
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> edges;
    vector<int> result;

    edges = {{1, 2}, {1, 3}, {2, 3}};
    result = solution.findRedundantDirectedConnection(edges);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    edges = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    result = solution.findRedundantDirectedConnection(edges);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    edges = {{2, 1}, {3, 1}, {4, 2}, {1, 4}};
    result = solution.findRedundantDirectedConnection(edges);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}
