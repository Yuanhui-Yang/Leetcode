825. Friends Of Appropriate Ages
https://leetcode.com/problems/friends-of-appropriate-ages/

Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person. 

Person A will NOT friend request person B (B != A) if any of the following conditions are true:

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
Otherwise, A will friend request B.

Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.

How many total friend requests are made?

Example 1:

Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.
Example 2:

Input: [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
Example 3:

Input: [20,30,100,110,120]
Output: 
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
 

Notes:

1 <= ages.length <= 20000.
1 <= ages[i] <= 120.

#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        array<int, 121> A = f1(ages);
        int result = 0;
        for (const auto & age : ages) {
            int lower = (age % 2) ? (age + 1) / 2 + 7 : (age + 2) / 2 + 7;
            int upper = age;
            for (int i = lower; i <= upper; ++i) {
                result += A[i];
            }
            if (lower <= age and age <= upper) {
                --result;
            }
        }
        return result;
    }
private:
    array<int, 121> f1(vector<int>& ages) {
        array<int, 121> result;
        result.fill(0);
        for (const auto & i : ages) {
            ++result[i];
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> ages;
    int result;

    ages = {16, 16};
    result = solution.numFriendRequests(ages);
    cout << result << '\n';

    ages = {16, 17, 18};
    result = solution.numFriendRequests(ages);
    cout << result << '\n';

    ages = {20, 30, 100, 110, 120};
    result = solution.numFriendRequests(ages);
    cout << result << '\n';

    return 0;
}
