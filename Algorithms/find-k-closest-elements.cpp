// 658. Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements/

/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
*/

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int sz = arr.size();
		if (sz == 0) {
			return {};
		}
		if (sz <= k) {
			return arr;
		}
		int id = distance(begin(arr), lower_bound(begin(arr), end(arr), x));
		int a = id - 1, b = id;
		vector<int> result;
		for (int i = 0; i < k; ++i) {
			if (a < 0 and b >= sz) {
				break;
			}
			else if (a < 0) {
				result.push_back(arr[b]);
				++b;
			}
			else if (b >= sz) {
				result.push_back(arr[a]);
				--a;
			}
			else if (abs(x - arr[a]) <= abs(x - arr[b])) {
				result.push_back(arr[a]);
				--a;
			}
			else {
				result.push_back(arr[b]);
				++b;
			}
		}
		sort(begin(result), end(result));
		return result;
	}
};