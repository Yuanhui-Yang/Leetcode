1739. Building Boxes
https://leetcode.com/problems/building-boxes/

You have a cubic storeroom where the width, length, and height of the room are all equal to n units. You are asked to place n boxes in this room where each box is a cube of unit side length. There are however some rules to placing the boxes:

You can place the boxes anywhere on the floor.
If box x is placed on top of the box y, then each side of the four vertical sides of the box y must either be adjacent to another box or to a wall.
Given an integer n, return the minimum possible number of boxes touching the floor.

 

Example 1:



Input: n = 3
Output: 3
Explanation: The figure above is for the placement of the three boxes.
These boxes are placed in the corner of the room, where the corner is on the left side.
Example 2:



Input: n = 4
Output: 3
Explanation: The figure above is for the placement of the four boxes.
These boxes are placed in the corner of the room, where the corner is on the left side.
Example 3:



Input: n = 10
Output: 6
Explanation: The figure above is for the placement of the ten boxes.
These boxes are placed in the corner of the room, where the corner is on the back side.
 

Constraints:

1 <= n <= 109

class Solution:
    def minimumBoxes(self, n: int) -> int:

        def f1(m):
            i = 1
            j = 1
            result = 0
            while m >= 0:
                result += 1
                m -= i
                j += 1
                i += j
            result -= 1
            return result

        def f2(m):
            result = 0
            i = 1
            j = 1
            while m > 0:
                m -= 1
                result += i
                j += 1
                i += j
            return result

        def f3(m):
            result = 0
            i = 1
            while m > 0:
                result += 1
                m -= i
                i += 1
            return result
            
        a = f1(n)
        # print(a)
        b = f2(a)
        # print(b)
        c = n - b
        # print(c)
        d = f3(c)
        # print(d)
        e = a * (a + 1) // 2
        return d + e