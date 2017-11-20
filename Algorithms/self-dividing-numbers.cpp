#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        while (left <= right) {
            if (f1(left)) {
                result.push_back(left);
            }
            ++left;
        }
        return result;
    }
private:
    bool f1(int num) {
        int a = num, b;
        while (a > 0) {
            b = a % 10;
            a /= 10;
            if (b == 0 or num % b != 0) {
                return false;
            }
        }
        return true;
    }
};

int main(void) {
    Solution solution;
    int left, right;
    vector<int> result;
    
    left = 1;
    right = 22;
    result = solution.selfDividingNumbers(left, right);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}