765. Couples Holding Hands
https://leetcode.com/problems/couples-holding-hands/

N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

Example 1:

Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
Example 2:

Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.
Note:

len(row) is even and in the range of [4, 60].
row is guaranteed to be a permutation of 0...len(row)-1.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<list<int>> A = f1(row), B = f2(A);
        int sz = B.size(), result = sz;
        for (int i = 0; i < sz; ++i) {
            if (!B[i].empty()) {
                --result;
                int prev = i, curr = B[prev].front();
                f3(B, prev, curr);
                while (curr != i) {
                    int next = B[curr].front();
                    prev = curr;
                    curr = next;
                    f3(B, prev, curr);
                }
            }
        }
        return result;
    }
private:
    vector<list<int>> f1(vector<int>& row) {
        int sz = row.size(), N = sz / 2;
        vector<list<int>> result(N);
        for (int i = 0; i < sz; ++i) {
            int a = row[i] / 2, b = i / 2;
            result[a].push_back(b);
        }
        return result;
    }
    vector<list<int>> f2(vector<list<int>> & A) {
        int sz = A.size();
        vector<list<int>> result(sz);
        for (int i = 0; i < sz; ++i) {
            int a = A[i].front(), b = A[i].back();
            result[a].push_back(b);
            result[b].push_back(a);
        }
        return result;
    }
    void f3(vector<list<int>> & B, int from, int to) {
        B[from].erase(find(B[from].begin(), B[from].end(), to));
        B[to].erase(find(B[to].begin(), B[to].end(), from));
    }
};

int main(void) {
    Solution solution;
    vector<int> row;
    int result;
    
    row ={0, 2, 1, 3};
    result = solution.minSwapsCouples(row);
    cout << result << '\n';

    row ={3, 2, 0, 1};
    result = solution.minSwapsCouples(row);
    cout << result << '\n';
    
    return 0;
}