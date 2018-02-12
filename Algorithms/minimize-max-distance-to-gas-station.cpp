774. Minimize Max Distance to Gas Station
https://leetcode.com/problems/minimize-max-distance-to-gas-station/

On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

Return the smallest possible value of D.

Example:

Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
Note:

stations.length will be an integer in range [10, 2000].
stations[i] will be an integer in range [0, 10^8].
K will be an integer in range [1, 10^6].
Answers within 10^-6 of the true value will be accepted as correct.

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int sz = stations.size();
        if (sz <= 1) {
            return 0;
        }
        vector<double> A;
        for (int i = 0; i + 1 < sz; ++i) {
            double distance = abs(stations[i + 1] - stations[i]);
            if (distance > 0) {
                A.push_back(distance);
            }
        }
        double a = 0, b = 1e8;
        while (b - a > 1e-6) {
            double c = (a + b) / 2.0;
            if (f1(stations, K, c)) {
                b = c;
            }
            else {
                a = c;
            }
        }
        return a;
    }
private:
    bool f1(vector<int>& stations, int K, double target) {
        int sz = stations.size(), cnt = 0;
        for (int i = 0; i + 1 < sz; ++i) {
            cnt += floor((stations[i + 1] - stations[i]) / target);
        }
        return cnt <= K;
    }
};

int main(void) {
    Solution solution;
    vector<int> stations;
    int K;
    double result;
    
    stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    K = 9;
    result = solution.minmaxGasDist(stations, K);
    cout << result << '\n';
    
    return 0;
}