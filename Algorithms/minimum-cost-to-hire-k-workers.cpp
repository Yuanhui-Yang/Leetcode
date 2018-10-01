857. Minimum Cost to Hire K Workers
https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.

 

Example 1:

Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 
 

Note:

1 <= K <= N <= 10000, where N = quality.length = wage.length
1 <= quality[i] <= 10000
1 <= wage[i] <= 10000
Answers within 10^-5 of the correct answer will be considered correct.

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

struct Worker {
    int quality, wage;
    Worker() {
        this->quality = 1;
        this->wage = 0;
    }
    Worker(int quality, int wage) {
        this->quality = quality;
        this->wage = wage;
    }
    double price() const {
        double result = this->wage;
        result /= this->quality;
        return result;
    }
    bool operator < (const Worker & other) const {
        return (this->wage * other.quality) < (this->quality * other.wage);
    }
};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int sz = quality.size();
        vector<Worker> workers(sz);
        for (int i = 0; i < sz; ++i) {
            workers[i] = Worker(quality[i], wage[i]);
        }
        sort(workers.begin(), workers.end());
        double result = numeric_limits<double>::max();
        int sum_quality = 0;
        priority_queue<int> max_heap;
        for (const auto & worker : workers) {
            sum_quality += worker.quality;
            max_heap.push(worker.quality);
            while (max_heap.size() > K) {
                sum_quality -= max_heap.top();
                max_heap.pop();
            }
            if (max_heap.size() == K) {
                result = min(result, sum_quality * worker.price());
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> quality, wage;
    int K;
    double result;

    quality = {10, 20, 5};
    wage = {70, 50, 30};
    K = 2;
    result = solution.mincostToHireWorkers(quality, wage, K);
    cout << result << '\n';

    quality = {3, 1, 10, 10, 1};
    wage = {4, 8, 2, 2, 7};
    K = 3;
    result = solution.mincostToHireWorkers(quality, wage, K);
    cout << result << '\n';

    return 0;
}