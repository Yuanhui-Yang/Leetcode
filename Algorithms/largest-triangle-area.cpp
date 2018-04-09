812. Largest Triangle Area
https://leetcode.com/problems/largest-triangle-area/

You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.


Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0;
        for (int sz = points.size(), i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                for (int k = j + 1; k < sz; ++k) {
                    double value = f1(points[i], points[j], points[k]);
                    if (i == 0 and j == 1 and k == 2) {
                        result = value;
                    }
                    else if (result < value) {
                        result = value;
                    }
                }
            }
        }
        return 0.5 * result;
    }
private:
    double f1(vector<int> & a, vector<int> & b, vector<int> & c) {
        int x1 = b[0] - a[0];
        int y1 = b[1] - a[1];
        int x2 = c[0] - a[0];
        int y2 = c[1] - a[1];
        return abs(x1 * y2 - y1 * x2);
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> points;
    double result;

    points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    result = solution.largestTriangleArea(points);
    cout << result << '\n';

    return 0;
}
