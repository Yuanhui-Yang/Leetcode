// 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/

/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		array<int, 26> A;
		A.fill(0);
		for (const auto & i : tasks) {
			++A[i - 'A'];
		}
		priority_queue<int> pq;
		for (const auto & i : A) {
			if (i > 0) {
				pq.push(i);
			}
		}
		int result = 0;
		while (!pq.empty() and pq.top() > 1) {
			queue<int> q;
			int i = 0;
			while (i <= n) {
				if (!pq.empty()) {
					if (pq.top() > 1) {
						q.push(pq.top() - 1);
					}
					pq.pop();
				}
				++result;
				++i;
			}
			while (!q.empty()) {
				pq.push(q.front());
				q.pop();
			}
		}
		result += pq.size();
		return result;
	}
};

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int sz = tasks.size();
		array<int, 26> A;
		A.fill(0);
		for (int i = 0; i < sz; ++i) {
			++A[tasks[i] - 'A'];
		}
		sort(begin(A), end(A));
		int result = 0;
		while (A.back() > 1) {
			result += n + 1;
			for (int i = 0; i <= n; ++i) {
				if (i < 26 and A[25 - i] > 0) {
					--A[25 - i];
				}
			}
			sort(begin(A), end(A));
		}
		result += accumulate(begin(A), end(A), 0);
		return result;
	}
};