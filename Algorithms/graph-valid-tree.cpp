// 261. Graph Valid Tree
// https://leetcode.com/problems/graph-valid-tree/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        int sz = edges.size();
        if (n != sz + 1) {
            return false;
        }
        f1(n);
        return f2(edges);
    }
private:
    vector<int> A, B;
    void f1(int n) {
        A.resize(n, 0);
        iota(A.begin(), A.end(), 0);
        B.resize(n, 1);
    }
    bool f2(vector<pair<int, int>> & edges) {
        for (auto & edge : edges) {
            if (f3(edge)) {
                return false;
            }
        }
        for (auto & i : A) {
            if (find(i) != find(A[0])) {
                return false;
            }
        }
        return true;
    }
    bool f3(pair<int, int> & edge) {
        int x = find(edge.first), y = find(edge.second);
        if (x == y) {
            return true;
        }
        if (B[x] > B[y]) {
            swap(x, y);
        }
        A[x] = y;
        B[y] += B[x];
        return false;
    }
    int find(int node) {
        while (node != A[node]) {
            A[node] = A[A[node]];
            node = A[node];
        }
        return node;
    }
};

int main(void) {
	Solution solution;
	int n = 5;
	vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 5;
	edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 5;
	edges = {{0, 1}, {1, 2}, {3, 4}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 4;
	edges = {{0, 1}, {2, 3}, {1, 2}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 2;
	edges.clear();
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 1;
	edges.clear();
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 3;
	edges = {{1, 0}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 3;
	edges = {{1, 0}, {2, 0}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 3;
	edges = {{2, 0}, {2, 1}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 6;
	edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {3, 5}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
