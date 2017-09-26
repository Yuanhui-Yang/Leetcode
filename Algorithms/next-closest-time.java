// 681. Next Closest Time
// https://leetcode.com/problems/next-closest-time/

/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
*/

import java.util.Arrays;
import java.lang.StringBuilder;

class Solution {
	public static String nextClosestTime(String time) {
		int[] curr = new int[2];
		String[] timeStr = time.split(":");
		curr[0] = Integer.parseInt(timeStr[0]);
		curr[1] = Integer.parseInt(timeStr[1]);
		boolean[] A = new boolean[10];
		Arrays.fill(A, false);
		A[time.charAt(0) - '0'] = true;
		A[time.charAt(1) - '0'] = true;
		A[time.charAt(3) - '0'] = true;
		A[time.charAt(4) - '0'] = true;
		do {
			f1(curr);
		} while (!f2(A, curr));
		StringBuilder result = new StringBuilder();
		result.append((char)(curr[0] / 10 + '0'));
		result.append((char)(curr[0] % 10 + '0'));
		result.append(':');
		result.append((char)(curr[1] / 10 + '0'));
		result.append((char)(curr[1] % 10 + '0'));
		return result.toString();
	}
	private static void f1(int[] curr) {
		++curr[1];
		if (curr[1] >= 60) {
			curr[1] = 0;
			++curr[0];
			if (curr[0] >= 24) {
				curr[0] = 0;
			}
		}
	}
	private static boolean f2(boolean[] A, int[] curr) {
		return A[curr[0] / 10] && A[curr[0] % 10] && A[curr[1] / 10] && A[curr[1] % 10];
	}
	public static void main(String[] args) {
		String time, result;
		
		time = "19:34";
		result = nextClosestTime(time);
		System.out.println(result);

		time = "23:59";
		result = nextClosestTime(time);
		System.out.println(result);
	}
}