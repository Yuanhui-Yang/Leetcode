313. Super Ugly Number
https://leetcode.com/problems/super-ugly-number/

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();
        if (n < 1 or sz < 1) {
            return 0;
        }
        vector<int> A, B(sz, 0);
        A.push_back(1);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        for (int i = 0; i < sz; ++i) {
            pq.push({primes[i], i});
        }
        for (int i = 1; i < n; ++i) {
            int val = pq.top()[0];
            A.push_back(val);
            while (!pq.empty() and pq.top()[0] == val) {
                int id = pq.top()[1];
                pq.pop();
                ++B[id];
                pq.push({primes[id] * A[B[id]], id});
            }
        }
        return A.back();
    }
};

int main(void) {
    Solution solution;
    vector<int> primes;
    int n, result;
    
    primes = {2, 7, 13, 19};
    n = 12;
    result = solution.nthSuperUglyNumber(n, primes);
    cout << result << '\n';
    
    return 0;
}