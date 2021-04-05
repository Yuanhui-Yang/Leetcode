1775. Equal Sum Arrays With Minimum Number of Operations
https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/

You are given two arrays of integers nums1 and nums2, possibly of different lengths. The values in the arrays are between 1 and 6, inclusive.

In one operation, you can change any integer's value in any of the arrays to any value between 1 and 6, inclusive.

Return the minimum number of operations required to make the sum of values in nums1 equal to the sum of values in nums2. Return -1​​​​​ if it is not possible to make the sum of the two arrays equal.

 

Example 1:

Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
- Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
- Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
- Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
Example 2:

Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
Output: -1
Explanation: There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make them equal.
Example 3:

Input: nums1 = [6,6], nums2 = [1]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed. 
- Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
- Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
- Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[i] <= 6

class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        s1 = sum(nums1)
        s2 = sum(nums2)
        if s1 == s2:
            return 0
        if s1 > s2:
            return self.minOperations(nums2, nums1)

        diff = s2 - s1
        nums1.sort()
        nums2.sort()
        
        d1 = 6 - nums1[0]
        d2 = nums2[-1] - 1
        
        if d1 == 0 and d2 == 0:
            return -1
        
        if diff <= d1 or diff <= d2:
            return 1
        
        if d1 > d2:
            nums1[0] = 6
            result = self.minOperations(nums1, nums2)
            return result + 1 if result >= 0 else -1
        else:
            nums2[-1] = 1
            result = self.minOperations(nums1, nums2)
            return result + 1 if result >= 0 else -1

class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        s1 = sum(nums1)
        s2 = sum(nums2)
        if s1 == s2:
            return 0
        if s1 > s2:
            return self.minOperations(nums2, nums1)

        nums1.sort()
        nums2.sort()
        sz1 = len(nums1)
        sz2 = len(nums2)
        def f1(start1, s1, end2, s2):
            # print(start1, s1, end2, s2)
            if s1 == s2:
                return 0
            d1 = 6 - nums1[start1] if start1 < sz1 else 0
            d2 = nums2[end2] - 1 if end2 >= 0 else 0
            diff = s2 - s1
            if d1 == 0 and d2 == 0:
                return -1
            if diff <= d1 or diff <= d2:
                return 1
            if d1 > d2:
                result = f1(start1 + 1, s1 + d1, end2, s2)
                return 1 + result if result >= 0 else -1
            else:
                result = f1(start1, s1, end2 - 1, s2 - d2)
                return 1 + result if result >= 0 else -1
        
        return f1(0, s1, sz2 - 1, s2)