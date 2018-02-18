56. Merge Intervals
https://leetcode.com/problems/merge-intervals/

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Comp {
    bool operator() (const Interval & a, const Interval & b) {
        if (a.start == b.start) {
            return a.end < b.end;
        }
        return a.start < b.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), Comp());
        int sz = intervals.size(), i = 0;
        vector<Interval> result;
        while (i < sz) {
            int a = intervals[i].start, b = intervals[i].end;
            while (i + 1 < sz and intervals[i + 1].start <= b) {
                b = max(b, intervals[i + 1].end);
                ++i;
            }
            result.push_back(Interval(a, b));
            ++i;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<Interval> intervals, result;
    
    intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    result = solution.merge(intervals);
    for (const auto & i : result) {
        cout << i.start << ',' << i.end << '\t';
    }
    cout << '\n';
    
    return 0;
}