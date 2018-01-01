// 740. Delete and Earn
// https://leetcode.com/problems/delete-and-earn/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> A = f1(nums);
        return f2(A);
    }
private:
    map<int, int> f1(vector<int> & nums) {
        map<int, int> result;
        for (const auto & i : nums) {
            result[i] += i;
        }
        return result;
    }
    int f2(map<int, int> & A) {
        if (A.empty()) {
            return 0;
        }
        int result = 0, prev = 0, curr = 0;
        for (const auto & i : A) {
            curr = result;
            if (A.count(i.first - 1)) {
                result = max(result, prev + i.second);
            }
            else {
                result = max(result, curr + i.second);
            }
            prev = curr;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int result;
    
    nums = {3, 4, 2};
    result = solution.deleteAndEarn(nums);
    cout << result << '\n';
    
    nums = {2, 2, 3, 3, 3, 4};
    result = solution.deleteAndEarn(nums);
    cout << result << '\n';
    
    return 0;
}