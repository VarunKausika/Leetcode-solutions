class Solution:
    def convert(self, s: str, numRows: int) -> str:
        string = ""
        if len(s) > numRows and numRows!=1:
            sum = 2*(numRows - 1)
            for row in range(numRows):
                cadence = [1, 0]
                diffs = [sum - 2*row, 2*row]
                if 0 in diffs:
                    diffs = [sum]*2
                i = row
                string += s[i]
                while i < len(s):
                    i = i + diffs[0]*cadence[0] + diffs[1]*cadence[1]
                    if i < len(s):
                        string += s[i]
                        cadence = cadence[::-1]
            return string
        else:
            return s