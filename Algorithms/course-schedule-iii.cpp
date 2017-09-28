// 630. Course Schedule III
// https://leetcode.com/problems/course-schedule-iii/

/*
There are n different online courses numbered from 1 to n. Each course has some duration(course length) t and closed on dth day. A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.

Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.

Example:
Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
Output: 3
Explanation: 
There're totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
Note:
The integer 1 <= d, t, n <= 10,000.
You can't take two courses simultaneously.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

struct Comp {
	bool operator() (const vector<int> & a, const vector<int> & b) {
		if (a[1] == b[1]) {
			return a[0] < b[0];
		}
		return a[1] < b[1];
	}
};

class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		int sz = courses.size(), i = 0, time = 0;
		if (sz <= 1) {
			return sz;
		}
		sort(begin(courses), end(courses), Comp());
		priority_queue<int> pq;
		pq.push(courses[0][0]);
		i = 1;
		time = courses[0][0];
		while (i < sz) {
			if (time + courses[i][0] <= courses[i][1]) {
				time += courses[i][0];
				pq.push(courses[i][0]);
			}
			else if (courses[i][0] < pq.top()) {
				time += -pq.top() + courses[i][0];
				pq.pop();
				pq.push(courses[i][0]);
			}
			++i;
		}
		return pq.size();
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> courses;
	int result;

	courses = {{7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18}};
	result = solution.scheduleCourse(courses);
	cout << result << '\n';
	
	courses = {{1, 2}, {2, 3}};
	result = solution.scheduleCourse(courses);
	cout << result << '\n';
	
	courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
	result = solution.scheduleCourse(courses);
	cout << result << '\n';
	
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct Comp {
	bool operator() (const vector<int> & a, const vector<int> & b) {
		if (a[1] == b[1]) {
			return a[0] < b[0];
		}
		return a[1] < b[1];
	}
};

class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		int sz = courses.size(), i = 0, j = 0, k = 0, l = 0, m = 0, time = 0;
		if (sz <= 1) {
			return sz;
		}
		sort(begin(courses), end(courses), Comp());
		vector<vector<int>> A;
		A.push_back(courses[0]);
		time = courses[0][0];
		i = 1;
		while (i < sz) {
			if (time + courses[i][0] <= courses[i][1]) {
				time += courses[i][0];
				A.push_back(courses[i]);
			}
			else {
				j = A.size();
				k = time;
				l = -1;
				for (m = 0; m < j; ++m) {
					if (time - A[m][0] + courses[i][0] < k) {
						k = time - A[m][0] + courses[i][0];
						l = m;
					}
				}
				if (l >= 0) {
					time += - A[l][0] + courses[i][0];
					swap(A[l], courses[i]);
				}
			}
			++i;
		}
		return A.size();
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> courses;
	int result;

	courses = {{7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18}};
	result = solution.scheduleCourse(courses);
	cout << result << '\n';
	
	courses = {{1, 2}, {2, 3}};
	result = solution.scheduleCourse(courses);
	cout << result << '\n';
	
	courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
	result = solution.scheduleCourse(courses);
	cout << result << '\n';
	
	return 0;
}