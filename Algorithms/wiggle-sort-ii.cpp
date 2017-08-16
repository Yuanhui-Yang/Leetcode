// 324. Wiggle Sort II
// https://leetcode.com/problems/wiggle-sort-ii/

/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int sz = nums.size(), mid = sz / 2;
        sort(begin(nums), end(nums));
        if (sz < 3) {
            return;
        }
        vector<int> A(sz);
        int i = mid - 1 + sz % 2, j = sz - 1, k = 0;
        while (k < sz) {
            if (k < sz and i >= 0) {
                A[k] = nums[i];
                --i;
                ++k;
            }
            if (k < sz and j >= 0) {
                A[k] = nums[j];
                --j;
                ++k;
            }
        }
        nums = A;
    }
};

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int sz = nums.size(), mid = sz / 2;
		sort(begin(nums), end(nums));
		if (sz < 3) {
			return;
		}
		vector<int> A(sz);
		if (sz % 2) {
			int i = mid, j = sz - 1, k = 0;
			while (k < sz) {
				if (k < sz and i >= 0) {
					A[k] = nums[i];
					--i;
					++k;
				}
				if (k < sz and j >= 0) {
					A[k] = nums[j];
					--j;
					++k;
				}
			}
		}
		else {
			int i = mid - 1, j = sz - 1, k = 0;
			while (k < sz) {
				if (k < sz and i >= 0) {
					A[k] = nums[i];
					--i;
					++k;
				}
				if (k < sz and j >= 0) {
					A[k] = nums[j];
					--j;
					++k;
				}
			}
		}
		nums = A;
	}
};