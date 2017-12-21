// 733. Flood Fill
// https://leetcode.com/problems/flood-fill/

/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int X = image.size(), Y = X == 0 ? 0 : image[0].size(), oldColor = 0, sz = 0, i = 0, j = 0;
        array<int, 2> f;
        if (sr < 0 or sr >= X or sc < 0 or sc >= Y) {
            return image;
        }
        oldColor = image[sr][sc];
        if (oldColor == newColor) {
            return image;
        }
        array<int, 4> dx({-1, 0, 1, 0}), dy({0, -1, 0, 1});
        queue<array<int, 2>> q;
        q.push({sr, sc});
        image[sr][sc] = -newColor;
        while (!q.empty()) {
            sz = q.size();
            while (sz-- > 0) {
                f = q.front();
                q.pop();
                i = 0;
                while (i < 4) {
                    f[0] += dx[i];
                    f[1] += dy[i];
                    if (f[0] >= 0 and f[0] < X and f[1] >= 0 and f[1] < Y and image[f[0]][f[1]] == oldColor) {
                        image[f[0]][f[1]] = -newColor;
                        q.push({f[0], f[1]});
                    }
                    f[0] -= dx[i];
                    f[1] -= dy[i];
                    ++i;
                }
            }
        }
        i = 0;
        while (i < X) {
            j = 0;
            while (j < Y) {
                if (image[i][j] == -newColor) {
                    image[i][j] = newColor;
                }
                ++j;
            }
            ++i;
        }
        return image;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> image, result;
    int sr, sc, newColor;
    
    image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    sr = 1;
    sc = 1;
    newColor = 2;
    result = solution.floodFill(image, sr, sc, newColor);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }
    
    return 0;
}