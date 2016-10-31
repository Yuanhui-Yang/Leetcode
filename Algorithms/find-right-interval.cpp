// 436. Find Right Interval
// https://leetcode.com/problems/find-right-interval/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iterator>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	vector<int> findRightInterval(vector<Interval>& intervals) {
		vector<int> result;
		vector<pair<int, int>> start2index;
		const int n = intervals.size();
		for (int i = 0; i < n; i++)
			start2index.push_back(make_pair(intervals[i].start, i));
		sort(begin(start2index), end(start2index), [](const pair<int, int>& a, const pair<int, int>& b) {
			return a.first < b.first;
		});
		for (const auto &i : intervals) {
			vector<pair<int, int>>::iterator it = lower_bound(begin(start2index), end(start2index), make_pair(i.end, -1), [](const pair<int, int>& a, const pair<int, int>& b) {
				return a.first < b.first;
			});
			result.push_back(it == end(start2index) ? -1 : it->second);
		}
		return result;
	}
};
// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	vector<int> findRightInterval(vector<Interval>& intervals) {
// 		const int n = intervals.size();
// 		vector<int> result(n, -1);
// 		for (int i = 0; i < n; i++) {
// 			int distance = INT_MAX;
// 			for (int j = 0; j < n; j++) {
// 				if (j != i && intervals[j].start >= intervals[i].end && intervals[j].start - intervals[i].end < distance) {
// 					result[i] = j;
// 					distance = intervals[j].start - intervals[i].end;
// 				}
// 			}
// 		}
// 		return result;
// 	}
// };
// END: Time Limit Exceeded
int main (void) {
	Solution solution;
	vector<Interval> intervals;
	for (const auto &i : solution.findRightInterval(intervals)) cout << i << '\t';
	cout << "\tPassed\n";
	intervals = { {1,2} };
	for (const auto &i : solution.findRightInterval(intervals)) cout << i << '\t';
	cout << "\tPassed\n";
	intervals = { {3,4}, {2,3}, {1,2} };
	for (const auto &i : solution.findRightInterval(intervals)) cout << i << '\t';
	cout << "\tPassed\n";
	intervals = { {1,4}, {2,3}, {3,4} };
	for (const auto &i : solution.findRightInterval(intervals)) cout << i << '\t';
	cout << "\tPassed\n";		
	cout << "\nPassed All\n";	
	return 0;
}