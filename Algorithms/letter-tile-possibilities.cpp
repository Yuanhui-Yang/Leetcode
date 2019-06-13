1079. Letter Tile Possibilities
https://leetcode.com/problems/letter-tile-possibilities/

You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

 

Example 1:

Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: "AAABBC"
Output: 188
 

Note:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> A;
        string path;
        vector<bool> unvisited(tiles.size(), true);
        f1(A, tiles, path, unvisited);
        return A.size();
    }
private:
    void f1(unordered_set<string> & A, string & tiles, string & path, vector<bool> & unvisited)
    {
        if (!path.empty())
        {
            A.insert(path);
        }
        for (int sz = tiles.size(), i = 0; i < sz; ++i)
        {
            if (unvisited[i])
            {
                unvisited[i] = false;
                path.push_back(tiles[i]);
                f1(A, tiles, path, unvisited);
                path.pop_back();
                unvisited[i] = true;
            }
        }
    }
};

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> A;
        sort(tiles.begin(), tiles.end());
        do
        {
            for (int sz = tiles.size(), status = 1; status < (1 << sz); ++status)
            {
                string s;
                for (int i = 0; i < sz; ++i)
                {
                    if (status & (1 << i))
                    {
                        s.push_back(tiles[i]);
                    }
                }
                A.insert(s);
            }
        } while (next_permutation(tiles.begin(), tiles.end()));
        return A.size();
    }
};