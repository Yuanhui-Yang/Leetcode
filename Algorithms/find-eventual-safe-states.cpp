802. Find Eventual Safe States
https://leetcode.com/problems/find-eventual-safe-states/

In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.

Illustration of graph

Note:

graph will have length at most 10000.
The number of edges in the graph will not exceed 32000.
Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<vector<int>> rgraph(sz);
        vector<int> indegree(sz, 0);
        for (int i = 0; i < sz; ++i) {
            for (const auto & j : graph[i]) {
                rgraph[j].push_back(i);
                ++indegree[i];
            }
        }
        vector<int> result;
        queue<int> q;
        for (int i = 0; i < sz; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            result.push_back(from);
            for (const auto & to : rgraph[from]) {
                if (--indegree[to] == 0) {
                    q.push(to);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> graph;
    vector<int> result;
    
    graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    result = solution.eventualSafeNodes(graph);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}
