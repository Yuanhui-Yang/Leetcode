1037. Valid Boomerang
https://leetcode.com/problems/valid-boomerang/

A boomerang is a set of 3 points that are all distinct and not in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.

 

Example 1:

Input: [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: [[1,1],[2,2],[3,3]]
Output: false
 

Note:

points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        vector<int> p = points[0], q = points[1], r = points[2];
        vector<int> a = {q[0] - p[0], q[1] - p[1]}, b = {r[0] - p[0], r[1] - p[1]};
        return f1(a, b);
    }
private:
    int f1(vector<int> & a, vector<int> & b)
    {
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        return x1 * y2 - y1 * x2;
    }
};