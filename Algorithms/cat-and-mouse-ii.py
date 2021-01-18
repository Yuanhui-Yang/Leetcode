1728. Cat and Mouse II
https://leetcode.com/problems/cat-and-mouse-ii/

A game is played by a cat and a mouse named Cat and Mouse.

The environment is represented by a grid of size rows x cols, where each element is a wall, floor, player (Cat, Mouse), or food.

Players are represented by the characters 'C'(Cat),'M'(Mouse).
Floors are represented by the character '.' and can be walked on.
Walls are represented by the character '#' and cannot be walked on.
Food is represented by the character 'F' and can be walked on.
There is only one of each character 'C', 'M', and 'F' in grid.
Mouse and Cat play according to the following rules:

Mouse moves first, then they take turns to move.
During each turn, Cat and Mouse can jump in one of the four directions (left, right, up, down). They cannot jump over the wall nor outside of the grid.
catJump, mouseJump are the maximum lengths Cat and Mouse can jump at a time, respectively. Cat and Mouse can jump less than the maximum length.
Staying in the same position is allowed.
Mouse can jump over Cat.
The game can end in 4 ways:

If Cat occupies the same position as Mouse, Cat wins.
If Cat reaches the food first, Cat wins.
If Mouse reaches the food first, Mouse wins.
If Mouse cannot get to the food within 1000 turns, Cat wins.
Given a rows x cols matrix grid and two integers catJump and mouseJump, return true if Mouse can win the game if both Cat and Mouse play optimally, otherwise return false.

 

Example 1:



Input: grid = ["####F","#C...","M...."], catJump = 1, mouseJump = 2
Output: true
Explanation: Cat cannot catch Mouse on its turn nor can it get the food before Mouse.
Example 2:



Input: grid = ["M.C...F"], catJump = 1, mouseJump = 4
Output: true
Example 3:

Input: grid = ["M.C...F"], catJump = 1, mouseJump = 3
Output: false
Example 4:

Input: grid = ["C...#","...#F","....#","M...."], catJump = 2, mouseJump = 5
Output: false
Example 5:

Input: grid = [".M...","..#..","#..#.","C#.#.","...#F"], catJump = 3, mouseJump = 1
Output: true
 

Constraints:

rows == grid.length
cols = grid[i].length
1 <= rows, cols <= 8
grid[i][j] consist only of characters 'C', 'M', 'F', '.', and '#'.
There is only one of each character 'C', 'M', and 'F' in grid.
1 <= catJump, mouseJump <= 8

class Solution:
    def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
        X, Y = len(grid), len(grid[0])
        
        def h1(x, y):
            return x * Y + y
        def h2(index):
            return index // Y, index % Y
        
        def f1():
            cat = -1
            mouse = -1
            for i in range(X):
                for j in range(Y):
                    ch = grid[i][j]
                    index = h1(i, j)
                    if ch == 'C':
                        cat = index
                    elif ch == 'M':
                        mouse = index
            return cat, mouse
        
        cat, mouse = f1()
        
        @cache
        def f2(cat, mouse, step):
            if step > 2 * X * Y:
                return False
            if cat == mouse:
                return False
            catX, catY = h2(cat)
            mouseX, mouseY = h2(mouse)
            if grid[catX][catY] == 'F':
                return False
            if grid[mouseX][mouseY] == 'F':
                return True
            dx = [-1, 0, 1, 0]
            dy = [0, -1, 0, 1]
            if step % 2:
                for i in range(4):
                    for j in range(catJump + 1):
                        nextCatX = catX + dx[i] * j
                        nextCatY = catY + dy[i] * j
                        nextCat = h1(nextCatX, nextCatY)
                        if 0 <= nextCatX and nextCatX < X and 0 <= nextCatY and nextCatY < Y and grid[nextCatX][nextCatY] != '#':
                            if not f2(nextCat, mouse, step + 1):
                                return False
                        else:
                            break;
                return True
            else:
                for i in range(4):
                    for j in range(mouseJump + 1):
                        nextMouseX = mouseX + dx[i] * j
                        nextMouseY = mouseY + dy[i] * j
                        nextMouse = h1(nextMouseX, nextMouseY)
                        if 0 <= nextMouseX and nextMouseX < X and 0 <= nextMouseY and nextMouseY < Y and grid[nextMouseX][nextMouseY] != '#':
                            if f2(cat, nextMouse, step + 1):
                                return True
                        else:
                            break;
                return False

        return f2(cat, mouse, 0)