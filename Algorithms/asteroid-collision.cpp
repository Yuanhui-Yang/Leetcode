#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (const auto & i : asteroids) {
            if (i == 0) {
                continue;
            }
            while (!result.empty() and result.back() > 0 and i < 0 and result.back() < -i) {
                result.pop_back();
            }
            if (result.empty()) {
                result.push_back(i);
            }
            else if (i > 0) {
                result.push_back(i);
            }
            else if (result.back() < 0) {
                result.push_back(i);
            }
            else if (result.back() == -i) {
                result.pop_back();
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> asteroids, result;
    
    asteroids = {5, 10, -5};
    result = solution.asteroidCollision(asteroids);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    asteroids = {8, -8};
    result = solution.asteroidCollision(asteroids);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    asteroids = {10, 2, -5};
    result = solution.asteroidCollision(asteroids);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    asteroids = {-2, -1, 1, 2};
    result = solution.asteroidCollision(asteroids);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}
