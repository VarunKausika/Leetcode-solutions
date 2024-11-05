from itertools import groupby

class Solution:
    def minChanges(self, s: str) -> int:
        """
        Algo:
        
        Greedy
        """
            
        changes = 0
        repeat_count = 0
        l = list(s)
        for index, number in enumerate(l):
            if index == 0:
                repeat_count+=1
            else:
                if number == l[index-1]:
                    repeat_count += 1
                    
                elif number != l[index-1] and repeat_count%2 == 1:
                    l[index] = str(int(not(bool(number))))
                    changes += 1
                    repeat_count += 1
                
                elif number != l[index-1] and repeat_count%2 == 0:
                    repeat_count = 1
        
        return changes
                    
        