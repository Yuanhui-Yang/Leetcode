207. Course Schedule
https://leetcode.com/problems/course-schedule/

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        f1(numCourses);
        f2(prerequisites);
        return f3();
    }
private:
    vector<vector<bool>> A;
    vector<bool> B;
    vector<int> C;
    int N;
    void f1(int N) {
        A.resize(N, vector<bool>(N, false));
        B.resize(N, false);
        C.resize(N, 0);
        this->N = N;
    }
    void f2(vector<pair<int, int>> & prerequisites) {
        for (const auto & i : prerequisites) {
            int from = i.second, to = i.first;
            if (0 <= from and from < N and 0 <= to and to < N) {
                if (!A[from][to]) {
                    A[from][to] = true;
                    B[from] = true;
                    B[to] = true;
                    ++C[to];
                }
            }
        }
    }
    bool f3() {
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (B[i] and C[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (int i = 0; i < N; ++i) {
                if (A[front][i]) {
                    A[front][i] = false;
                    --C[i];
                    if (C[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(void) {
    Solution solution;
    int numCourses;
    vector<pair<int, int>> prerequisites;
    bool result;
    
    numCourses = 2;
    prerequisites = {{1, 0}};
    result = solution.canFinish(numCourses, prerequisites);
    cout << boolalpha << result << '\n';

    numCourses = 2;
    prerequisites = {{1, 0}, {0, 1}};
    result = solution.canFinish(numCourses, prerequisites);
    cout << boolalpha << result << '\n';
    
    return 0;
}