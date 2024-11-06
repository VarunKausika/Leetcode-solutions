class Solution:
    def myAtoi(self, s: str) -> int:
        def range_check(x: int) -> int:
            if x >= -2**31 and x <= 2**31 -1:
                return x
            elif x < -2**31:
                return -2**31
            elif x > 2**31 -1:
                return 2**31 -1
            
        new_str = s.lstrip()
        
        if new_str == "":
            return 0
        
        if new_str[0] == '-' or new_str[0] == '+':
            if new_str[0] == '-':
                multiplier = -1
            else:
                multiplier = 1
            new_str = new_str[1:].lstrip('0')  
        
        else:
            new_str = new_str.lstrip('0')
            multiplier = 1
            
        if new_str == '':
            return 0
        else:
            tmp = ''
            for ele in new_str:
                if ele in [str(i) for i in range(10)]:
                    tmp += ele
                else:
                    break
            if tmp != '':
                return range_check(multiplier*int(tmp))
            else:
                return 0
