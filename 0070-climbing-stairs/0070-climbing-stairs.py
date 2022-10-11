import math
class Solution:
    def climbStairs(self, n: int) -> int:
        ways = 0
        for i in range(int(n/2)+1):
            ways += math.factorial(n-i)/(math.factorial(i)*math.factorial(n-2*i))
        return int(ways)
        
                                         
                                         