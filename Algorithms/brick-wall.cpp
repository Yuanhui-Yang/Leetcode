554. Brick Wall
https://leetcode.com/problems/brick-wall/

There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Example:
Input: 
[[1,2,2,1],
 [3,1,2],
 [1,3,2],
 [2,4],
 [3,1,2],
 [1,3,1,1]]
Output: 2
Explanation: 

Note:
The width sum of bricks in different rows are the same and won't exceed INT_MAX.
The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. Total number of bricks of the wall won't exceed 20,000.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int result = 0;
        unordered_map<int, int> A;
        for (const auto & w : wall) {
            for (int len = 0, sz = w.size(), i = 0; i + 1 < sz; ++i) {
                len += w[i];
                result = max(result, ++A[len]);
            }
        }
        return wall.size() - result;
    }
};

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        f1(wall);
        return f2(wall);
    }
private:
    void f1(vector<vector<int>>& wall) {
        for (auto & w : wall) {
            for (int sz = w.size(), i = 1; i < sz; ++i) {
                w[i] += w[i - 1];
            }
        }
    }
    int f2(vector<vector<int>>& wall) {
        int result = wall.size();
        for (const auto & w : wall) {
            for (int sz = w.size(), i = 0; i + 1 < sz; ++i) {
                int cnt = 0;
                for (const auto & v : wall) {
                    cnt += !binary_search(v.begin(), v.end(), w[i]);
                }
                if (cnt < result) {
                    result = cnt;
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> wall;
    int result;

    wall = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
    result = solution.leastBricks(wall);
    cout << result << '\n';

    return 0;
}
