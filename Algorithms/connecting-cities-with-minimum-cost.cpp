1135. Connecting Cities With Minimum Cost
https://leetcode.com/problems/connecting-cities-with-minimum-cost/

There are N cities numbered from 1 to N.

You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect city1 and city2 together.  (A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)

Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) that connects those two cities together.  The cost is the sum of the connection costs used. If the task is impossible, return -1.

 

Example 1:



Input: N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: 
Choosing any 2 edges will connect all cities so we choose the minimum 2.
Example 2:



Input: N = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: 
There is no way to connect all cities even if all edges are used.
 

Note:

1 <= N <= 10000
1 <= connections.length <= 10000
1 <= connections[i][0], connections[i][1] <= N
0 <= connections[i][2] <= 10^5
connections[i][0] != connections[i][1]

struct Comp
{
    bool operator() (vector<int> & a, vector<int> & b)
    {
        return a[2] < b[2];
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), Comp());
        vector<int> A(N + 1), B(N + 1, 1), C(N + 1, 0);
        iota(A.begin(), A.end(), 0);
        B[0] = 0;
        int N0 = N, result = -1;
        for (auto & connection : connections)
        {
            int a = connection[0], b = connection[1], c = connection[2];
            int ra = F(A, a), rb = F(A, b);
            U(A, B, C, N0, ra, rb, c);
        }
        for (int i = 1; i <= N; ++i)
        {
            if (B[i] == N)
            {
                result = C[i];
            }
        }
        return result;
    }
private:
    int F(vector<int> & A, int node)
    {
        while (node != A[node])
        {
            node = A[node] = A[A[node]];
        }
        return node;
    }
    void U(vector<int> & A, vector<int> & B, vector<int> & C, int & N0, int a, int b, int c)
    {
        int ra = F(A, a), rb = F(A, b);
        if (ra != rb)
        {
            if (B[ra] < B[rb])
            {
                swap(ra, rb);
            }
            --N0;
            A[rb] = ra;
            B[ra] += B[rb];
            C[ra] += c + C[rb];
        }
    }
};