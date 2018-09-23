847. Shortest Path Visiting All Nodes
https://leetcode.com/problems/shortest-path-visiting-all-nodes/

An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:

Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
 

Note:

1 <= graph.length <= 12
0 <= graph[i].length < graph.length

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int sz = graph.size(), N = 1 << sz;
        vector<vector<int> > A = vector<vector<int> > (sz, vector<int>(N, -1));
        queue<array<int, 2>> q;
        for (int i = 0; i < sz; ++i) {
            A[i][1 << i] = 0;
            array<int, 2> e = {i, 1 << i};
            q.push(e);
        }
        int result = 0;
        while (!q.empty()) {
            int sz1 = q.size();
            while (sz1-- > 0) {
                array<int, 2> from = q.front();
                q.pop();
                if (from[1] + 1 == N) {
                    return result;
                }
                for (const auto & to : graph[from[0]]) {
                    int nstatus = from[1] | (1 << to);
                    if (A[to][nstatus] < 0 or result + 1 < A[to][nstatus]) {
                        array<int, 2> e = {to, nstatus};
                        q.push(e);
                        A[to][nstatus] = result + 1;
                    }
                }
            }
            ++result;
        }
        return -1;
    }
};


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int sz = graph.size(), N = 1 << sz;
        vector<vector<vector<int> > > A(sz, vector<vector<int> >(sz, vector<int>(N, -1)));
        queue<array<int, 3>> q;
        for (int i = 0; i < sz; ++i) {
            A[i][i][1 << i] = 0;
            array<int, 3> e = {i, i, 1 << i};
            q.push(e);
        }
        int result = 0;
        while (!q.empty()) {
            int sz1 = q.size();
            while (sz1-- > 0) {
                array<int, 3> from = q.front();
                q.pop();
                if (from[2] + 1 == N) {
                    return result;
                }
                for (const auto & to : graph[from[1]]) {
                    int nstatus = from[2] | (1 << to);
                    if (A[from[0]][to][nstatus] < 0 or result + 1 < A[from[0]][to][nstatus]) {
                        array<int, 3> e = {from[0], to, nstatus};
                        q.push(e);
                        A[from[0]][to][nstatus] = result + 1;
                    }
                }
            }
            ++result;
        }
        return -1;
    }
};