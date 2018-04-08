815. Bus Routes
https://leetcode.com/problems/bus-routes/

We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.

Example:
Input: 
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
Output: 2
Explanation: 
The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Note:

1 <= routes.length <= 500.
1 <= routes[i].length <= 500.
0 <= routes[i][j] < 10 ^ 6.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) {
            return 0;
        }
        f1(routes);
        return f3(routes, S, T);
    }
private:
    int cnt;
    vector<vector<int>> graph;
    void f1(vector<vector<int>>& routes) {
        cnt = routes.size();
        graph.resize(cnt);
        for (auto & route : routes) {
            sort(route.begin(), route.end());
        }
        for (int i = 0; i + 1 < cnt; ++i) {
            for (int j = i + 1; j < cnt; ++j) {
                if (f2(routes[i], routes[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }
    bool f2(vector<int> & A, vector<int> & B) {
        int sz1 = A.size(), sz2 = B.size(), i = 0, j = 0;
        while (i < sz1 and j < sz2) {
            int x = A[i], y = B[j];
            if (x == y) {
                return true;
            }
            else if (x < y) {
                ++i;
            }
            else {
                ++j;
            }
        }
        return false;
    }
    int f3(vector<vector<int>>& routes, int S, int T) {
        int Src = -1, Dest = -2;
        for (int i = 0; i < cnt and Src != Dest; ++i) {
            if (binary_search(routes[i].begin(), routes[i].end(), S)) {
                Src = i;
            }
            if (binary_search(routes[i].begin(), routes[i].end(), T)) {
                Dest = i;
            }
        }
        if (Src < 0 or Dest < 0) {
            return -1;
        }
        if (Src == Dest) {
            return 1;
        }
        queue<int> q;
        q.push(Src);
        int result = 0;
        vector<bool> A(cnt, true);
        A[Src] = false;
        while (!q.empty()) {
            ++result;
            int sz = q.size();
            while (sz-- > 0) {
                int from = q.front();
                if (from == Dest) {
                    return result;
                }
                q.pop();
                for (const auto & to : graph[from]) {
                    if (A[to]) {
                        A[to] = false;;
                        q.push(to);
                    }
                }
            }
        }
        return -1;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> routes;
    int S, T, result;
    
    routes = {{1, 2, 7}, {3, 6, 7}};
    S = 1;
    T = 6;
    result = solution.numBusesToDestination(routes, S, T);
    cout << result << '\n';
    
    return 0;
}
