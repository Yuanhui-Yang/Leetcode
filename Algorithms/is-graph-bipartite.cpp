785. Is Graph Bipartite?
https://leetcode.com/problems/is-graph-bipartite/

Given a graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent ubsets.
 

Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<int> colors(sz, -1);
        for (int i = 0; i < sz; ++i) {
            if (colors[i] < 0) {
                colors[i] = 0;
                stack<int> stk;
                stk.push(i);
                while (!stk.empty()) {
                    int from = stk.top(), color = colors[from];
                    stk.pop();
                    for (const auto & to : graph[from]) {
                        int & ncolor = colors[to];
                        if (ncolor == color) {
                            return false;
                        }
                        if (ncolor < 0) {
                            ncolor = 1 - color;
                            stk.push(to);
                        }
                    }
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<int> A(sz, -1);
        if (!f1(graph, A)) {
            return false;
        }
        return true;
    }
private:
    bool f1(vector<vector<int>>& graph, vector<int> & A) {
        int sz = A.size(), i = 0;
        if (sz <= 0) {
            return false;
        }
        for (int i = 0; i < sz; ++i) {
            if (A[i] < 0) {
                if (!f3(graph, A, i)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool f2(vector<vector<int>>& graph, vector<int> & A, int id) {
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int front = q.front(), color = A[front];
            q.pop();
            for (const auto & i : graph[front]) {
                if (A[i] < 0) {
                    A[i] = 1 - color;
                    q.push(i);
                }
                else if (A[i] == color) {
                    return false;
                }
            }
        }
        return true;
    }
    bool f3(vector<vector<int>>& graph, vector<int> & A, int id) {
        stack<int> s;
        s.push(id);
        while (!s.empty()) {
            int top = s.top(), color = A[top];
            s.pop();
            for (const auto & i : graph[top]) {
                if (A[i] < 0) {
                    A[i] = 1 - color;
                    s.push(i);
                }
                else if (A[i] == color) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> graph;
    bool result;
    
    graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    result = solution.isBipartite(graph);
    cout << boolalpha << result << '\n';

    graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    result = solution.isBipartite(graph);
    cout << boolalpha << result << '\n';
    
    return 0;
}
