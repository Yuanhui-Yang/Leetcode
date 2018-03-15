621. Task Scheduler
https://leetcode.com/problems/task-scheduler/

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> A;
        A.fill(0);
        for (const auto & i : tasks) {
            int id = i - 'A';
            ++A[id];
        }
        priority_queue<array<int, 2>> pq;
        for (int i = 0; i < 26; ++i) {
            if (A[i] > 0) {
                pq.push({A[i], i});
            }
        }
        int result = 0;
        while (!pq.empty()) {
            queue<array<int, 2>> q;
            int i = 0;
            while (i < n + 1 and !pq.empty()) {
                ++i;
                array<int, 2> top = pq.top();
                pq.pop();
                ++result;
                --top[0];
                if (top[0] > 0) {
                    q.push(top);
                }
            }
            if (!q.empty()) {
                result += n + 1 - i;
            }
            while (!q.empty()) {
                array<int, 2> front = q.front();
                q.pop();
                pq.push(front);
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<char> tasks;
    int n, result;
    
    tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    n = 2;
    result = solution.leastInterval(tasks, n);
    cout << result << '\n';
    
    return 0;
}