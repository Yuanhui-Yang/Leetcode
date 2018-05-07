// 253. Meeting Rooms II
// https://leetcode.com/problems/meeting-rooms-ii/

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	int minMeetingRooms(vector<Interval>& intervals) {
		sort(begin(intervals), end(intervals), Comp());
		priority_queue<int, vector<int>, greater<int>> min_heap;
		for (const auto & i : intervals) {
			if (!min_heap.empty() and min_heap.top() <= i.start) {
				min_heap.pop();
			}
			min_heap.push(i.end);
		}
		return min_heap.size();
	}
private:
	struct Comp {
		bool operator() (const Interval & a, const Interval & b) {
			return a.start < b.start;
		}
	};
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> A;
        for (const auto & interval : intervals) {
            ++A[interval.start];
            --A[interval.end];
        }
        int result = 0, cnt = 0;
        for (const auto & i : A) {
            cnt += i.second;
            result = max(result, cnt);
        }
        return result;
    }
};
