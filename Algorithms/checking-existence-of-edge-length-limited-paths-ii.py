1724. Checking Existence of Edge Length Limited Paths II
https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/

An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes, and the graph may not be connected.

Implement the DistanceLimitedPathsExist class:

DistanceLimitedPathsExist(int n, int[][] edgeList) Initializes the class with an undirected graph.
boolean query(int p, int q, int limit) Returns true if there exists a path from p to q such that each edge on the path has a distance strictly less than limit, and otherwise false.
 

Example 1:



Input
["DistanceLimitedPathsExist", "query", "query", "query", "query"]
[[6, [[0, 2, 4], [0, 3, 2], [1, 2, 3], [2, 3, 1], [4, 5, 5]]], [2, 3, 2], [1, 3, 3], [2, 0, 3], [0, 5, 6]]
Output
[null, true, false, true, false]

Explanation
DistanceLimitedPathsExist distanceLimitedPathsExist = new DistanceLimitedPathsExist(6, [[0, 2, 4], [0, 3, 2], [1, 2, 3], [2, 3, 1], [4, 5, 5]]);
distanceLimitedPathsExist.query(2, 3, 2); // return true. There is an edge from 2 to 3 of distance 1, which is less than 2.
distanceLimitedPathsExist.query(1, 3, 3); // return false. There is no way to go from 1 to 3 with distances strictly less than 3.
distanceLimitedPathsExist.query(2, 0, 3); // return true. There is a way to go from 2 to 0 with distance < 3: travel from 2 to 3 to 0.
distanceLimitedPathsExist.query(0, 5, 6); // return false. There are no paths from 0 to 5.
 

Constraints:

2 <= n <= 104
0 <= edgeList.length <= 104
edgeList[i].length == 3
0 <= ui, vi, p, q <= n-1
ui != vi
p != q
1 <= disi, limit <= 109
At most 104 calls will be made to query.

class DistanceLimitedPathsExist:

    def __init__(self, n: int, edgeList: List[List[int]]):
        def f1():
            A = [list() for i in range(n)]
            for edge in edgeList:
                a = edge[0]
                b = edge[1]
                c = edge[2]
                A[a].append([b, c])
                A[b].append([a, c])
            visited = set()
            node = 0
            mst = []
            q = []

            while len(visited) < n:
                while len(q) == 0:
                    flag = False
                    if node not in visited:
                        flag = True
                        visited.add(node)
                        for i in A[node]:
                            a = i[0]
                            b = i[1]
                            if a not in visited:
                                q.append([node, a, b])
                    node += 1
                    if flag:
                        break

                q.sort(key = lambda e: e[2])
                front = []
                while len(q) > 0:
                    front = q.pop(0)
                    a = front[0]
                    b = front[1]
                    c = front[2]
                    if b not in visited:
                        break
                if b not in visited:
                    mst.append(front)
                    visited.add(b)
                    for i in A[b]:
                        d = i[0]
                        e = i[1]
                        if d not in visited:
                            q.append([b, d, e])
            return mst

        mst = f1()
        # print(mst)
        
        def f2():
            self.parent = [[-1, -1] for i in range(n)]
            tree = [list() for i in range(n)]
            for i in mst:
                if len(i) == 3:
                    a = i[0]
                    b = i[1]
                    c = i[2]
                    tree[a].append([b, c])
                    tree[b].append([a, c])
            node = 0
            visited = set()
            q = list()
            while len(visited) < n:
                while len(q) == 0:
                    flag = False
                    if node not in visited:
                        flag = True
                        visited.add(node)
                        q.append(node)
                    node += 1
                    if flag:
                        break
                while len(q) > 0:
                    a = q.pop(0)
                    for i in tree[a]:
                        b = i[0]
                        c = i[1]
                        if b not in visited:
                            q.append(b)
                            visited.add(b)
                            self.parent[b] = [a, c]
                            
        f2()
        # print(self.parent)
            

    def query(self, p: int, q: int, limit: int) -> bool:
        def root(a):
            x = self.parent[a]
            b = x[0]
            c = x[1]
            if b < 0:
                return a
            else:
                return root(b)
        rp = root(p)
        rq = root(q)
        if rp != rq:
            return False

        def lca(x, y):
            visited = set()
            while x >= 0:
                visited.add(x)
                x = self.parent[x][0]
            while y >= 0 and y not in visited:
                y = self.parent[y][0]
            return y

        node = lca(p, q)
        # print(node)
        
        def f1(x):
            while x != node:
                y = self.parent[x]
                a = y[0]
                b = y[1]
                if b >= limit:
                    return False
                else:
                    x = a
            return True

        return f1(p) and f1(q)


# Your DistanceLimitedPathsExist object will be instantiated and called as such:
# obj = DistanceLimitedPathsExist(n, edgeList)
# param_1 = obj.query(p,q,limit)