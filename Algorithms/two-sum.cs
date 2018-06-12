using System;
using System.Collections.Generic;

public class Solution {
    public static int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> A = new Dictionary<int, int>();
        for (int sz = nums.Length, i = 0; i < sz; ++i) {
            int val = nums[i], complement = target - val;
            if (A.ContainsKey(complement)) {
                return new int[] {A[complement], i};
            }
            A[val] = i;
        }
        return null;
    }
    public static void Main() {
        int[] nums, result;
        int target;
        
        nums = new int[] {2, 7, 11, 15};
        target = 9;
        result = TwoSum(nums, target);
        foreach (int i in result) {
            Console.Write(i);
            Console.Write(' ');
        }
        Console.WriteLine();
    }
}
