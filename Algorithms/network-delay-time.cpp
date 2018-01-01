// 744. Network Delay Time
// https://leetcode.com/problems/network-delay-time/

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if (times.empty() or N <= 0 or K <= 0 or N < K) {
            return 0;
        }
        vector<list<array<int, 2>>> graph(N);
        for (const auto & time : times) {
            graph[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        vector<int> dist(N, -1);
        dist[K - 1] = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> minHeap;
        minHeap.push({0, K - 1});
        int result = 0;
        while (!minHeap.empty()) {
            array<int, 2> top = minHeap.top();
            minHeap.pop();
            if (top[0] == dist[top[1]]) {
                result = top[0];
                for (const auto & neighbor : graph[top[1]]) {
                    if (dist[neighbor[0]] < 0 or top[0] + neighbor[1] < dist[neighbor[0]]) {
                        dist[neighbor[0]] = top[0] + neighbor[1];
                        minHeap.push({dist[neighbor[0]], neighbor[0]});
                    }

                }
            }
        }
        for (const auto & i : dist) {
            if (i < 0) {
                return -1;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> times;
    int N, K, result;
    
    times = {{1, 2, 1}, {2, 3, 2}, {1, 3, 4}};
    N = 3;
    K = 1;
    result = solution.networkDelayTime(times, N, K);
    cout << result << '\n';
    
    return 0;
}