1125. Smallest Sufficient Team
https://leetcode.com/problems/smallest-sufficient-team/

In a project, you have a list of required skills req_skills, and a list of people.  The i-th person people[i] contains a list of skills that person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill.  We can represent these teams by the index of each person: for example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].

Return any sufficient team of the smallest possible size, represented by the index of each person.

You may return the answer in any order.  It is guaranteed an answer exists.

 

Example 1:

Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]
Example 2:

Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
 

Constraints:

1 <= req_skills.length <= 16
1 <= people.length <= 60
1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
Elements of req_skills and people[i] are (respectively) distinct.
req_skills[i][j], people[i][j][k] are lowercase English letters.
It is guaranteed a sufficient team exists.

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int sz1 = req_skills.size(), sz2 = people.size(), INF = 1e9 + 7;
        vector<int> A(sz1 + 1);
        A[0] = 1;
        for (int i = 1; i <= sz1; ++i)
        {
            A[i] = 2 * A[i - 1];
        }
        vector<int> B(sz2, 0);
        for (int i = 0; i < sz2; ++i)
        {
            vector<string> & skills = people[i];
            for (const auto & j : skills)
            {
                vector<string>::iterator it = find(req_skills.begin(), req_skills.end(), j);
                int index = distance(req_skills.begin(), it);
                B[i] |= A[index];
            }
        }
        vector<vector<int>> C(sz2 + 1, vector<int>(A[sz1], INF));
        C[0][0] = 0;
        for (int i = 0; i < sz2; ++i)
        {
            for (int status = 0; status < A[sz1]; ++status)
            {
                C[i + 1][status] = min(C[i + 1][status], C[i][status]);
                int next_status = status | B[i];
                C[i + 1][next_status] = min(C[i + 1][next_status], 1 + C[i][status]);
            }
        }
        vector<int> result;
        for (int status = A[sz1] - 1, i = sz2 - 1; i >= 0; --i)
        {
            int prev_status = -1;
            for (int j = 0; j < A[sz1]; ++j)
            {
                if ((B[i] | j) == status)
                {
                    if (C[i][j] + 1 == C[i + 1][status])
                    {
                        prev_status = j;
                        break;
                    }
                }
            }
            if (prev_status >= 0)
            {
                status = prev_status;
                result.push_back(i);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};