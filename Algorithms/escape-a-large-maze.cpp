1036. Escape a Large Maze
https://leetcode.com/problems/escape-a-large-maze/

In a 1 million by 1 million grid, the coordinates of each grid square are (x, y) with 0 <= x, y < 10^6.

We start at the source square and want to reach the target square.  Each move, we can walk to a 4-directionally adjacent square in the grid that isn't in the given list of blocked squares.

Return true if and only if it is possible to reach the target square through a sequence of moves.

 

Example 1:

Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
Output: false
Explanation: 
The target square is inaccessible starting from the source square, because we can't walk outside the grid.
Example 2:

Input: blocked = [], source = [0,0], target = [999999,999999]
Output: true
Explanation: 
Because there are no blocked cells, it's possible to reach the target square.
 

Note:

0 <= blocked.length <= 200
blocked[i].length == 2
0 <= blocked[i][j] < 10^6
source.length == target.length == 2
0 <= source[i][j], target[i][j] < 10^6
source != target

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.empty() or source == target)
        {
            return true;
        }
        int X = 1e6, Y = X, cnt = 0;
        queue<vector<int>> q;
        q.push(source);
        unordered_set<long> visited;
        visited.insert(f1(source));
        for (auto & p : blocked)
        {
            visited.insert(f1(p));
        }
        array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
        while (!q.empty())
        {
            vector<int> from = q.front();
            q.pop();
            if (from == target)
            {
                return true;
            }
            ++cnt;
            if (cnt > 200 * 100)
            {
                return true;
            }
            for (int i = 0; i < 4; ++i)
            {
                vector<int> to(from);
                to[0] += dx[i];
                to[1] += dy[i];
                long to_key = f1(to);
                if (0 <= to[0] and to[0] < X and 0 <= to[1] and to[1] < Y and !visited.count(to_key))
                {
                    visited.insert(to_key);
                    q.push(to);
                }
            }
        }
        return false;
    }
private:
    long f1(vector<int> & point)
    {
        long x = point[0], y = point[1], z = 1e6;
        return z * x + y;
    }
};