using System;

public class Solution {
    public static int LengthOfLongestSubstring(string s) {
        int[] A = new int[512];
        int sz = s.Length, i = 0, j = 0, cnt = 0, result = 0;
        for (i = 0; i < 512; ++i) {
            A[i] = 0;
        }
        i = 0;
        while (j < sz) {
            if (A[s[j]] > 0) {
                ++cnt;
            }
            ++A[s[j]];
            ++j;
            while (cnt > 0) {
                --A[s[i]];
                if (A[s[i]] > 0) {
                    --cnt;
                }
                ++i;
            }
            if (result < j - i) {
                result = j - i;
            }
        }
        return result;
    }
    public static void Main() {
        string s;
        int result;

        s = "abcabcbb";
        result = LengthOfLongestSubstring(s);
        Console.WriteLine(result);

        s = "bbbbb";
        result = LengthOfLongestSubstring(s);
        Console.WriteLine(result);

        s = "pwwkew";
        result = LengthOfLongestSubstring(s);
        Console.WriteLine(result);
    }
}
