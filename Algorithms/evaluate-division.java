// 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/

/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

import java.util.HashMap;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Arrays;
import java.util.Queue;

class Solution {
	public static double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
		HashMap<String, Integer> A = new HashMap<>();
		int n = 0, i = 0, j = 0, k = 0, sz = equations.length;
		for (String[] p : equations) {
			if (!A.containsKey(p[0])) {
				A.put(p[0], n++);
			}
			if (!A.containsKey(p[1])) {
				A.put(p[1], n++);
			}
		}
		ArrayList<LinkedList<Pair>> B = new ArrayList<>();
		for (i = 0; i < n; ++i) {
			B.add(new LinkedList<>());
		}
		for (i = 0; i < sz; ++i) {
			j = A.get(equations[i][0]);
			k = A.get(equations[i][1]);
			B.get(j).add(new Pair(k, values[i]));
			B.get(k).add(new Pair(j, 1 / values[i]));
		}
		n = queries.length;
		double[] result = new double[n];
		for (i = 0; i < n; ++i) {
			if (!A.containsKey(queries[i][0]) || !A.containsKey(queries[i][1])) {
				result[i] = -1;
			}
			else {
				j = A.get(queries[i][0]);
				k = A.get(queries[i][1]);
				result[i] = f(B, j, k);
			}
		}
		return result;
	}
	private static double f(ArrayList<LinkedList<Pair>> B, int x, int y) {
		int n = B.size(), front = 0;
		double[] C = new double[n];
		Arrays.fill(C, -1);
		C[x] = 1;
		Queue<Integer> curr = new LinkedList<>();
		curr.add(x);
		while (!curr.isEmpty()) {
			front = curr.poll();
			if (front == y) {
				return C[y];
			}
			LinkedList<Pair> l = B.get(front);
			for (Pair p : l) {
				if (C[p.id] < 0) {
					curr.add(p.id);
					C[p.id] = p.val * C[front];
				}
			}
		}
		return -1;
	}
	private static class Pair {
		public int id;
		public double val;
		public Pair(int id, double val) {
			this.id = id;
			this.val = val;
		}
	}
	public static void main(String[] args) {
		String[][] equations, queries;
		double[] values, result;

		equations = new String[][] {{"a", "b"}, {"b", "c"}};
		values = new double[] {2.0, 3.0};
		queries = new String[][] {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
		result = calcEquation(equations, values, queries);
		System.out.println(Arrays.toString(result));
	}
}