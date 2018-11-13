939. Minimum Area Rectangle
https://leetcode.com/problems/minimum-area-rectangle/

Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 

Note:

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>>::iterator it = unique(points.begin(), points.end());
        int sz = distance(points.begin(), it);
        points.resize(sz);
        unordered_set<int> hashset;
        for (const auto & point : points)
        {
            int x = point[0], y = point[1], z = getHashkey(x, y);
            hashset.insert(z);
        }
        int result = 0;
        for (int i = 0; i + 1 < sz; ++i)
        {
            for (int j = i + 1; j < sz; ++j)
            {
                int ax = points[i][0], ay = points[i][1];
                int cx = points[j][0], cy = points[j][1];
                if (ax != cx and ay != cy)
                {
                    int bx = ax, by = cy, bz = getHashkey(bx, by);
                    int dx = cx, dy = ay, dz = getHashkey(dx, dy);
                    if (hashset.count(bz) and hashset.count(dz))
                    {
                        int area = getArea(points[i], points[j]);
                        if (result == 0 or area < result)
                        {
                            result = area;
                        }
                    }
                }
            }
        }
        return result;
    }
private:
    int getHashkey(int x, int y)
    {
        return 40001 * x + y;
    }
    int getArea(const vector<int> & a , const vector<int> & c)
    {
        int x = c[0] - a[0], y = c[1] - a[1];
        return abs(x * y);
    }
};