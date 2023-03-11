class Solution:
    def isValid(self, s: str) -> bool:
        if len(s)>=2:
            parens = {
                '}':'{', 
                ')':'(',
                ']':'['
            }
            count = {}
            recent = []
            flag = False
            for i in s:
                if i in parens.values():
                    try:
                        count[i]+=1
                    except:
                        count[i]=1
                    recent.append(i)
                else:
                    try:
                        if recent[-1]==parens[i]:
                            try:
                                count[parens[i]]-=1
                            except:
                                pass
                            del recent[-1]
                        else:
                            if parens[i] not in recent:
                                return False
                                exit()
                    except:
                        return False
                        exit()
            print(len(recent))
            print(set(count.values()))
            if set(count.values())=={0} and len(recent)==0:
                flag = True
            return flag
        else:
            return False
