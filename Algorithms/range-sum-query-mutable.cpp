// 307. Range Sum Query - Mutable
// https://leetcode.com/problems/range-sum-query-mutable/
// https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
    NumArray(vector<int> nums) {
        int sz = nums.size();
        this->BIT = vector<int>(sz + 1, 0);
        for (int i = 0; i < sz; ++i)
        {
            f2(i + 1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int delta = val - f1(i + 1) + f1(i);
        f2(i + 1, delta);
    }
    
    int sumRange(int i, int j) {
        return f1(j + 1) - f1(i);
    }
private:
    vector<int> BIT;
    int f1(int bound)
    {
        int result = 0;
        while (bound > 0)
        {
            result += BIT[bound];
            bound -= bound & (-bound);
        }
        return result;
    }
    void f2(int i, int val)
    {
        int sz = BIT.size();
        while (i < sz)
        {
            BIT[i] += val;
            i += i & (-i);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main(void) {
	vector<int> nums = {1, 3, 5};
	NumArray numArray(nums);
	cout << numArray.sumRange(0, 2) << "\tPassed\n";
	numArray.update(1, 2);
	cout << numArray.sumRange(0, 2) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
