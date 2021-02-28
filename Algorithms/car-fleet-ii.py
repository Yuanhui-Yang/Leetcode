1776. Car Fleet II
https://leetcode.com/problems/car-fleet-ii/

There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of length n, where cars[i] = [positioni, speedi] represents:

positioni is the distance between the ith car and the beginning of the road in meters. It is guaranteed that positioni < positioni+1.
speedi is the initial speed of the ith car in meters per second.
For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.

Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1 if the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.

 

Example 1:

Input: cars = [[1,2],[2,1],[4,3],[7,2]]
Output: [1.00000,-1.00000,3.00000,-1.00000]
Explanation: After exactly one second, the first car will collide with the second car, and form a car fleet with speed 1 m/s. After exactly 3 seconds, the third car will collide with the fourth car, and form a car fleet with speed 2 m/s.
Example 2:

Input: cars = [[3,4],[5,4],[6,3],[9,1]]
Output: [2.00000,1.00000,1.50000,-1.00000]
 

Constraints:

1 <= cars.length <= 105
1 <= positioni, speedi <= 106
positioni < positioni+1

class Solution:
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        sz = len(cars)
        result = [-1.0 for i in range(sz)]
        for i in range(sz):
            car = cars[i]
            car.append(i)

        def f1(A, currTime):
            l = len(A)
            t = 1e6
            targetId = -1
            for i in range(l - 1):
                a = A[i]
                b = A[i + 1]
                
                pa = a[0]
                sa = a[1]
                
                pb = b[0]
                sb = b[1]
                
                dt = (pb - pa) / (sa - sb) if sa > sb else 1e7
                
                if dt < t:
                    targetId = i
                    t = dt
            
            if targetId < 0:
                # output
                return result

            
            # print(t)
            nextTime = currTime + t
            # print(nextTime)
            B = []
            
            for i in range(l):
                if i != targetId:
                    car = A[i]
                    s = car[1]
                    dp = t * s
                    car[0] += dp
                    B.append(car)
            originalId = A[targetId][2]
            result[originalId] = nextTime
            
            return f1(B, nextTime)
            
        f1(cars, 0.0)
        return result