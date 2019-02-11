// 403. Frog Jump
// https://leetcode.com/problems/frog-jump/

/*
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
*/

#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> A;
        A[stones[0]].insert(0);
        array<int, 3> dk{-1, 0, 1};
        for (int sz = stones.size(), i = 0; i < sz; ++i)
        {
            int pos = stones[i];
            if (A.count(pos))
            {
                for (const auto & k : A[pos])
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        int nk = k + dk[j];
                        if (nk > 0)
                        {
                            int npos = pos + nk;
                            A[npos].insert(nk);   
                        }
                    }
                }
            }
        }
        return A.count(stones.back()) and !A[stones.back()].empty();
    }
};

class Solution {
public:
	bool canCross(vector<int>& stones) {
		int sz = stones.size(), i, j, k;
		if (sz == 0) {
			return false;
		}
		if (sz == 1) {
			return true;
		}
		vector<unordered_set<int>> A(sz);
		array<int, 3> B({-1, 0, 1});
		if (stones[1] != 1) {
			return false;
		}
		A[1].insert(1);
		for (i = 2; i < sz; ++i) {
			for (j = 1; j < i; ++j) {
				k = stones[i] - stones[j];
				for (const auto & l : B) {
					if (A[j].count(k + l)) {
						A[i].insert(k);
						break;
					}
				}
			}
		}
		return !A.back().empty();
	}
};

int main(void) {
	Solution solution;
	vector<int> stones;
	bool result;
	
	stones = {0, 1, 3, 5, 6, 8, 12, 17};
	result = solution.canCross(stones);
	cout << boolalpha << result << '\n';

	stones = {0, 1, 2, 3, 4, 8, 9, 11};
	result = solution.canCross(stones);
	cout << boolalpha << result << '\n';

	return 0;
}
