943. Find the Shortest Superstring
https://leetcode.com/problems/find-the-shortest-superstring/

Given an array A of strings, find any smallest string that contains each string in A as a substring.

We may assume that no string in A is substring of another string in A.

 
Example 1:

Input: ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
Example 2:

Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"
 

Note:

1 <= A.length <= 12
1 <= A[i].length <= 20

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        this->A = A;
        this->B = this->f1();
        this->C = this->f2();
        this->f3();
        return this->f4();
    }
private:
    vector<string> A;
    vector<int> B;
    vector<int> f1()
    {
        int N = this->A.size(), i;
        vector<int> result(N + 1);
        result[0] = 1;
        for (i = 1; i <= N; ++i)
        {
            result[i] = result[i - 1] << 1;
        }
        return result;
    }
    vector<vector<int>> C;
    vector<vector<int>> f2()
    {
        int N = this->A.size(), i, j, k, status, sz1, sz2, sz3;
        size_t index;
        string c;
        vector<vector<int>> result(N, vector<int>(N));
        for (i = 0; i < N; ++i)
        {
            const string & a = A[i];
            sz1 = a.size();
            for (j = 0; j < N; ++j)
            {
                if (i != j)
                {
                    const string & b = A[j];
                    sz2 = b.size();
                    sz3 = min(sz1, sz2);
                    result[i][j] = sz1 + sz2;
                    int & d = result[i][j];
                    for (k = sz3; k >= 1; --k)
                    {
                        c = a.substr(sz1 - k);
                        index = b.find(c);
                        if (index == 0)
                        {
                            d = sz2 - k;
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
    vector<vector<int>> D; // DP
    vector<vector<int>> E; // parent
    void f3()
    {
        int N = this->A.size(), X = this->B[N], status, i, j;
        this->D.resize(X, vector<int>(N, -1));
        this->E.resize(X, vector<int>(N, -1));
        for (i = 0; i < N; ++i)
        {
        	status = 1 << i;
        	this->D[status][i] = this->A[i].size();
        }
        for (status = 0; status < X; ++status) // current status
        {
            for (i = 0; i < N; ++i) // from
            {
                if ((status / this->B[i]) % 2 == 1)
                {
                    int from_cost = this->D[status][i];
                    if (from_cost >= 0)
                    {
                        for (j = 0; j < N; ++j) // to
                        {
                            if (i != j)
                            {
                                if ((status / this->B[j]) % 2 == 0)
                                {
                                    int next_status = status + this->B[j];
                                    int & to_cost = this->D[next_status][j];
                                    int tmp = from_cost + this->C[i][j];
                                    if (to_cost < 0 || tmp < to_cost)
                                    {
                                        to_cost = tmp;
                                        this->E[next_status][j] = i;
                                    }
                                }
                            } 
                        }   
                    }
                }
            }
        }
    }
    string f4()
    {
        int N = this->A.size(), X = this->B[N], status = X - 1, cost, tmp, i, j, k = N - 1;
        // cout << status << '\n';
        vector<string> result(N);
        cost = this->D[status][0];
        j = 0; // parent
        for (i = 1; i < N; ++i)
        {
            tmp = this->D[status][i];
            if (tmp >= 0)
            {
                if (cost < 0 || tmp < cost)
                {
                    cost = tmp;
                    j = i;
                }
            }
        }
        result[k--] = this->A[j];
        i = j;
        j = this->E[status][i];
        status -= this->B[i];
        while (k >= 0)
        {
        	tmp = this->A[j].size() - (this->A[i].size() - this->C[j][i]); // length
            result[k--] = this->A[j].substr(0, tmp);
            i = j;
            j = this->E[status][i];
            status -= this->B[i];
        }
        // for (vector<vector<int>>::iterator x = this->E.begin(); x != this->E.end(); ++x)
        // {
        // 	for (vector<int>::iterator y = x->begin(); y != x->end(); ++y)
        // 	{
        // 		cout << *y << '\t';
        // 	}
        // 	cout << '\n';
        // }
        return accumulate(result.begin(), result.end(), string());
    }
};

int main(void)
{
	Solution solution;
	vector<string> A;
	string line;
	while (cin >> line)
	{
		A.push_back(line);
	}
	cout << solution.shortestSuperstring(A) << '\n';
	return 0;
}