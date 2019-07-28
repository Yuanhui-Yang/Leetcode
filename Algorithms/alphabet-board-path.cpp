1138. Alphabet Board Path
https://leetcode.com/problems/alphabet-board-path/

On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].

Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.



We may make the following moves:

'U' moves our position up one row, if the position exists on the board;
'D' moves our position down one row, if the position exists on the board;
'L' moves our position left one column, if the position exists on the board;
'R' moves our position right one column, if the position exists on the board;
'!' adds the character board[r][c] at our current position (r, c) to the answer.
(Here, the only positions that exist on the board are positions with letters on them.)

Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.

 

Example 1:

Input: target = "leet"
Output: "DDR!UURRR!!DDD!"
Example 2:

Input: target = "code"
Output: "RR!DDRR!UUL!R!"
 

Constraints:

1 <= target.length <= 100
target consists only of English lowercase letters.

class Solution {
public:
    string alphabetBoardPath(string target) {
        array<array<int, 2>, 26> A;
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                int k = 5 * i + j;
                if (k < 26)
                {
                    A[k] = {i, j};
                }
            }
        }
        string result;
        array<int, 2> curr_pos;
        curr_pos.fill(0);
        char curr_ch = 'a';
        for (const auto next_ch : target)
        {
            array<int, 2> next_pos = A[next_ch - 'a'];
            if (curr_pos[0] == 5 and next_pos[0] == 5)
            {
                
            }
            else if (curr_pos[0] == 5)
            {
                {
                    result.push_back('U');
                }
                {
                    int dx = next_pos[0] - 4, dy = next_pos[1] - 0;
                    if (dx)
                    {
                        result.append(string(abs(dx), dx > 0 ? 'D' : 'U'));
                    }
                    if (dy)
                    {
                        result.append(string(abs(dy), dy > 0 ? 'R' : 'L'));
                    } 
                }
            }
            else if (next_pos[0] == 5)
            {
                {
                    int dx = 4 - curr_pos[0], dy = 0 - curr_pos[1];
                    if (dx)
                    {
                        result.append(string(abs(dx), dx > 0 ? 'D' : 'U'));
                    }
                    if (dy)
                    {
                        result.append(string(abs(dy), dy > 0 ? 'R' : 'L'));
                    } 
                }
                {
                    result.push_back('D');
                }
            }
            else
            {
                int dx = next_pos[0] - curr_pos[0], dy = next_pos[1] - curr_pos[1];
                if (dx)
                {
                    result.append(string(abs(dx), dx > 0 ? 'D' : 'U'));
                }
                if (dy)
                {
                    result.append(string(abs(dy), dy > 0 ? 'R' : 'L'));
                }   
            }
            result.push_back('!');
            swap(curr_pos, next_pos);
        }
        return result;
    }
};