1136. Parallel Courses
https://leetcode.com/problems/parallel-courses/

There are N courses, labelled from 1 to N.

We are given relations[i] = [X, Y], representing a prerequisite relationship between course X and course Y: course X has to be studied before course Y.

In one semester you can study any number of courses as long as you have studied all the prerequisites for the course you are studying.

Return the minimum number of semesters needed to study all courses.  If there is no way to study all the courses, return -1.

 

Example 1:



Input: N = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation: 
In the first semester, courses 1 and 2 are studied. In the second semester, course 3 is studied.
Example 2:



Input: N = 3, relations = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: 
No course can be studied because they depend on each other.
 

Note:

1 <= N <= 5000
1 <= relations.length <= 5000
relations[i][0] != relations[i][1]
There are no repeated relations in the input.

class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> graph(N + 1);
        vector<bool> seen(N + 1, false);
        vector<int> indegree(N + 1, 0);
        for (auto & relation : relations)
        {
            int from = relation[0], to = relation[1];
            graph[from].push_back(to);
            ++indegree[to];
        }
        queue<int> q;
        int cnt = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                seen[i] = true;
                ++cnt;
            }
        }
        int result = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz-- > 0)
            {
                int from = q.front();
                q.pop();
                for (auto to : graph[from])
                {
                    if (!seen[to])
                    {
                        if (--indegree[to] == 0)
                        {
                            ++cnt;
                            seen[to] = true;
                            q.push(to);
                        }
                    }
                }
            }
            ++result;
        }
        return cnt == N ? result : -1;
    }
};