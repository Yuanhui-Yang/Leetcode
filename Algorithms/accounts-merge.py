721. Accounts Merge
https://leetcode.com/problems/accounts-merge/

Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        root = []
        def find(node):
            # print(node)
            rnode = root[node]
            if node == rnode:
                return node
            else:
                root[node] = find(rnode)
                return root[node]
            
        def union(a, b):
            ra = find(a)
            rb = find(b)
            if ra != rb:
                root[rb] = ra
        
        cnt = 0
        email2id = {}
        email2name = {}
        X = len(accounts)
        # print(accounts)
        for i in range(X):
            account = accounts[i]
            Y = len(account)
            if Y >= 2:
                a = account[1]
                if a not in email2id:
                    email2id[a] = cnt
                    email2name[a] = account[0]
                    root.append(cnt)
                    cnt += 1
                ra = root[email2id[a]]
                # print(a, ra)
                for j in range(2, Y):
                    b = account[j]
                    if b not in email2id:
                        email2id[b] = cnt
                        email2name[b] = account[0]
                        root.append(cnt)
                        cnt += 1
                    rb = root[email2id[b]]
                    # print(b, rb)
                    # print(ra, rb)
                    union(ra, rb)
        # print(root)
        # print(email2id)
        A = {}
        for k, v in email2id.items():
            rv = find(v)
            if rv not in A:
                A[rv] = [k]
            else:
                A[rv].append(k)
        # print(A)
        
        result = []
        for v in A.values():
            v.sort()
            v.insert(0, email2name[v[0]])
            result.append(v)
        return result