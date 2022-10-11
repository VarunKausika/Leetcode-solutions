class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # If the string is empty
        if len(s) == 0:
            return 0
        
        lengthlist = []
        sublist = []
        characters = list(s)
        print(characters)
        
        index = 0
        rightpoint = 1
        while index <= len(s)-1:
            
            # rightpoint = rightpoint+1
            
            # If we haven't encountered this character before
            if characters[index] not in sublist:
                # If the character isn't the last one
                if index!=len(s)-1:
                    sublist.append(characters[index])
                    index+=1
                    rightpoint = index - len(sublist) + 1
                else:
                    sublist.append(characters[index])
                    lengthlist.append(len(sublist))
                    index+=1
                
            # If we have encountered this character before
            else:
                lengthlist.append(len(sublist))
                # In the case when we are not at the last element
                try:
                    sublist = [characters[rightpoint]]
                    rightpoint+=1
                # In the case that we are at the last element
                except:
                    lengthlist.append(1)
                index = rightpoint
                
        return max(lengthlist)