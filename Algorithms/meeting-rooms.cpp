// 252. Meeting Rooms
// https://leetcode.com/problems/meeting-rooms/

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
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

struct Comp {
    bool operator() (const Interval & a, const Interval & b) {
        return a.start < b.start;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), Comp());
        for (int sz = intervals.size(), i = 0; i + 1 < sz; ++i) {
            if (intervals[i + 1].start < intervals[i].end) {
                return false;
            }
        }
        return true;
    }
};
