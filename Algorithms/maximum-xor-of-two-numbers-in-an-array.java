// 421. Maximum XOR of Two Numbers in an Array
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

import java.util.Arrays;

class Solution {
	public static int findMaximumXOR(int[] nums) {
		int result = 0, val = 0;
		Node root = new Node();
		for (int i : nums) {
			f1(root, i);
		}
		for (int i : nums) {
			val = f2(root, i);
			if (result < val) {
				result = val;
			}
		}
		return result;
	}
	private static void f1(Node node, int val) {
		for (int i = 31; i >= 0; --i) {
			int id = val >> i;
			id &= 1;
			if (node.next[id] == null) {
				node.next[id] = new Node();
			}
			node = node.next[id];
		}
		node.val = val;
	}
	private static int f2(Node node, int val) {
		for (int i = 31; i >= 0; --i) {
			int id = val >> i;
			id &= 1;
			if (node.next[1 - id] != null) {
				node = node.next[1 - id];
			}
			else {
				node = node.next[id];
			}
		}
		return val ^ node.val;
	}
	private static class Node {
		public int val = 0;
		public Node[] next = null;
		public Node() {
			val = 0;
			next = new Node[2];
			Arrays.fill(next, null);
		}
	}
	public static void main(String[] args) {
		int[] nums = new int[]{3, 10, 5, 25, 2, 8};
		System.out.println(findMaximumXOR(nums));
	}
}