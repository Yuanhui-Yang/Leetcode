391. Perfect Rectangle
https://leetcode.com/problems/perfect-rectangle/

Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).


Example 1:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.

Example 2:

rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.

Example 3:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.

Example 4:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other.

#include <iostream>
#include <set>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<array<int, 4>> lines = f1(rectangles);
        int sz = lines.size(), i = 0, prev = -1, curr = 0;
        multiset<array<int, 2>> A;
        while (i < sz) {
            int x = lines[i][0];
            while (i < sz and lines[i][0] == x) {
                array<int, 2> interval({lines[i][2], lines[i][3]});
                if (lines[i][1] < 0) {
                    A.erase(interval);
                }
                else {
                    if (!f2(A, interval)) {
                        return false;
                    }
                    A.insert(interval);
                }
                ++i;
            }
            curr = f3(A);
            if (i + 1 < sz and curr == 0) {
                return false;
            }
            if (i + 1 < sz and prev > 0 and curr != prev) {
                return false;
            }
            prev = curr;
        }
        return curr == 0;
    }
private:
    vector<array<int, 4>> f1(vector<vector<int>>& rectangles) {
        vector<array<int, 4>> result;
        for (const auto & i : rectangles) {
            result.push_back(array<int, 4>({i[0], 1, i[1], i[3]}));
            result.push_back(array<int, 4>({i[2], -1, i[1], i[3]}));
        }
        sort(result.begin(), result.end());
        return result;
    }
    bool f2(multiset<array<int, 2>> & A, array<int, 2> & interval) {
        multiset<array<int, 2>>::iterator begin = A.begin(), end = A.end(), it = A.upper_bound(interval);
        if (it != begin and interval[0] < prev(it)->at(1)) {
            return false;
        }
        if (it != end and it->at(0) < interval[1]) {
            return false;
        }
        return true;
    }
    int f3(multiset<array<int, 2>> & A) {
        int result = 0;
        multiset<array<int, 2>>::iterator begin = A.begin(), end = A.end();
        while (begin != end) {
            int a = begin->at(0), b = begin->at(1);
            while (begin != end and begin->at(0) <= b) {
                b = max(b, begin->at(1));
                ++begin;
            }
            result += b - a;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> rectangles;
    bool result;

    rectangles = {{0, 0, 1, 1}, {0, 1, 1, 2}, {0, 2, 1, 3}, {0, 3, 1, 4}};
    result = solution.isRectangleCover(rectangles);
    cout << boolalpha << result << '\n';

    rectangles = {{0, 0, 5, 1}, {7, 0, 8, 2}, {5, 1, 6, 3}, {6, 0, 7, 2}, {4, 0, 5, 1}, {4, 2, 5, 3}, {2, 1, 4, 3}, {0, 2, 2, 3}, {0, 1, 2, 2}, {6, 2, 8, 3}, {5, 0, 6, 1}, {4, 1, 5, 2}};
    result = solution.isRectangleCover(rectangles);
    cout << boolalpha << result << '\n';

    rectangles = {{0, 0, 4, 1}, {0, 0, 4, 1}};
    result = solution.isRectangleCover(rectangles);
    cout << boolalpha << result << '\n';

    rectangles = {{0, 0, 4, 1}, {7, 0, 8, 2}, {6, 2, 8, 3}, {5, 1, 6, 3}, {4, 0, 5, 1}, {6, 0, 7, 2}, {4, 2, 5, 3}, {2, 1, 4, 3}, {0, 1, 2, 2}, {0, 2, 2, 3}, {4, 1, 5, 2}, {5, 0, 6, 1}};
    result = solution.isRectangleCover(rectangles);
    cout << boolalpha << result << '\n';

    rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
    result = solution.isRectangleCover(rectangles);
    cout << boolalpha << result << '\n';

    rectangles = {{1, 1, 2, 3}, {1, 3, 2, 4}, {3, 1, 4, 2}, {3, 2, 4, 4}};
    result = solution.isRectangleCover(rectangles);
    cout << boolalpha << result << '\n';

    rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {3, 2, 4, 4}};
    result = solution.isRectangleCover(rectangles);
    cout << boolalpha << result << '\n';

    rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {2, 2, 4, 4}};
    result = solution.isRectangleCover(rectangles);
    cout << boolalpha << result << '\n';

    return 0;
}