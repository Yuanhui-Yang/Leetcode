/*
 * @lc app=leetcode id=1349 lang=cpp
 *
 * [1349] Maximum Students Taking Exam
 *
 * https://leetcode.com/problems/maximum-students-taking-exam/description/
 *
 * algorithms
 * Hard (34.89%)
 * Likes:    146
 * Dislikes: 3
 * Total Accepted:    2.5K
 * Total Submissions: 7.3K
 * Testcase Example:  '[["#",".","#","#",".","#"],[".","#","#","#","#","."],["#",".","#","#",".","#"]]'
 *
 * Given a m * n matrix seats  that represent seats distributions in a
 * classroom. If a seat is broken, it is denoted by '#' character otherwise it
 * is denoted by a '.' character.
 * 
 * Students can see the answers of those sitting next to the left, right, upper
 * left and upper right, but he cannot see the answers of the student sitting
 * directly in front or behind him. Return the maximum number of students that
 * can take the exam together without any cheating being possible..
 * 
 * Students must be placed in seats in good condition.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: seats = [["#",".","#","#",".","#"],
 * [".","#","#","#","#","."],
 * ["#",".","#","#",".","#"]]
 * Output: 4
 * Explanation: Teacher can place 4 students in available seats so they don't
 * cheat on the exam. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: seats = [[".","#"],
 * ["#","#"],
 * ["#","."],
 * ["#","#"],
 * [".","#"]]
 * Output: 3
 * Explanation: Place all students in available seats. 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: seats = [["#",".",".",".","#"],
 * [".","#",".","#","."],
 * [".",".","#",".","."],
 * [".","#",".","#","."],
 * ["#",".",".",".","#"]]
 * Output: 10
 * Explanation: Place students in available seats in column 1, 3 and 5.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * seats contains only characters '.' and'#'.
 * m == seats.length
 * n == seats[i].length
 * 1 <= m <= 8
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int X = seats.size();
        int Y = X ? seats[0].size() : 0;
        int N = 1 << Y;
        vector<int> A(N, 0);
        int result = 0;
        for (int status = 0; status < N; ++status)
        {
            if (f1(Y, status))
            {
                if (f2(seats.front(), status))
                {
                    result = max(result, A[status] = f3(status));
                }
            }
        }
        for (int i = 1; i < X; ++i)
        {
            vector<char>& prev = seats[i - 1];
            vector<char>& curr = seats[i];
            vector<int> B(N, 0);
            for (int from = 0; from < N; ++from)
            {
                if (f1(Y, from))
                {
                    if (f2(prev, from))
                    {
                        for (int to = 0; to < N; ++to)
                        {
                            if (f1(Y, to))
                            {
                                if (f2(curr, to))
                                {
                                    if (f4(Y, from, to))
                                    {
                                        result = max(result, B[to] = max(B[to], A[from] + f3(to)));
                                    }
                                }
                            }
                        }
                    }
                }
            }
            swap(A, B);
        }
        return result;
    }
private:
    int f0(int n)
    {
        return 1 << n;
    }
    bool f1(int Y, int status)
    {
        for (int i = 0; i + 1 < Y; ++i)
        {
            if (f0(i) & status)
            {
                if (f0(i + 1) & status)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool f2(vector<char>& seat, int status)
    {
        int Y = seat.size();
        for (int i = 0; i < Y; ++i)
        {
            if (f0(i) & status)
            {
                if (seat[i] == '#')
                {
                    return false;
                }
            }
        }
        return true;
    }
    int f3(int status)
    {
        int result = 0;
        while (status)
        {
            ++result;
            status &= status - 1;
        }
        return result;
    }
    bool f4(int Y, int from, int to)
    {
        for (int i = 0; i < Y; ++i)
        {
            if (f0(i) & from)
            {
                if (i == 0)
                {
                    if (i + 1 < Y)
                    {
                        if (f0(i + 1) & to)
                        {
                            return false;
                        }
                    }
                }
                else if (i + 1 == Y)
                {
                    if (i - 1 >= 0)
                    {
                        if (f0(i - 1) & to)
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    if (i + 1 < Y)
                    {
                        if (f0(i + 1) & to)
                        {
                            return false;
                        }
                    }
                    if (i - 1 >= 0)
                    {
                        if (f0(i - 1) & to)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

