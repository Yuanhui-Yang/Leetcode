using System;

public class Solution {
    public static double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int sz1 = nums1.Length;
        int sz2 = nums2.Length;
        int sz3 = sz1 + sz2;
        return (sz3 % 2 == 0) ? 0.5 * f1(nums1, nums2, sz3 / 2) + 0.5 * f1(nums1, nums2, 1 + sz3 / 2) : f1(nums1, nums2, sz3 / 2 + 1);
    }
    private static int f1(int[] nums1, int[] nums2, int k) {
        int sz1 = nums1 == null ? 0 : nums1.Length;
        int sz2 = nums2 == null ? 0 : nums2.Length;
        if (sz1 == 0) {
            return nums2[k - 1];
        }
        if (sz2 == 0) {
            return nums1[k - 1];
        }
        int left = Math.Min(nums1[0], nums2[0]);
        int right = 1 + Math.Max(nums1[sz1 - 1], nums2[sz2 - 1]);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f2(nums1, nums2, mid) < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
    private static int f2(int[] nums1, int[] nums2, int val) {
        return f3(nums1, val) + f3(nums2, val);
    }
    private static int f3(int[] nums, int val) {
        int sz = nums == null ? 0 : nums.Length, left = 0, right = sz;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= val) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
    public static void Main() {
        int[] nums1, nums2;
        double result;

        nums1 = new int[] {1, 3};
        nums2 = new int[] {2};
        result = FindMedianSortedArrays(nums1, nums2);
        Console.WriteLine(result);
    }
}
