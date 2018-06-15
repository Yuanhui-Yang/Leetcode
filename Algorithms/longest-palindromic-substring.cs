using System;
using System.Collections.Generic;

public class Solution {
    public static string LongestPalindrome(string s) {
        string t = "#";
        foreach (char ch in s) {
            t += ch;
            t += '#';
        }
        int sz = t.Length, i = 0, j = 0, k = 0, x = 0, y = 0, z = 0, mc = 0, mr = 0;
        List<int> A = new List<int>(sz);
        for (i = 0; i < sz; ++i) {
            A.Add(0);
        }
        for (i = 0; i < sz; ++i) {
            j = 2 * x - i;
            z = 2 * x - y;
            if (z < j && z < j - A[j]) {
                A[i] = A[j];
            }
            else {
                k = 0;
                while (i - k >= 0 && i + k < sz && t[i - k] == t[i + k]) {
                    ++k;
                }
                --k;
                A[i] = k;
            }
            if (y < i + A[i]) {
                x = i;
                y = i + A[i];
            }
            if (mr < A[i]) {
                mc = i;
                mr = A[i];
            }
        }
        return s.Substring((mc - mr) / 2, mr);
    }
    public static void Main() {
        string s, result;

        s = "babad";
        result = LongestPalindrome(s);
        Console.WriteLine(result);

        s = "cbbd";
        result = LongestPalindrome(s);
        Console.WriteLine(result);
    }
}