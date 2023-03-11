class Solution:
    def intToRoman(self, num: int) -> str:
        roman_dict = {
            "I": 1, 
            "V": 5, 
            "X": 10, 
            "L": 50, 
            "C": 100, 
            "D": 500, 
            "M": 1000,
            "IV": 4,
            "IX": 9,
            "XL": 40, 
            "XC": 90,
            "CD": 400,
            "CM": 900
        }
        string = ""
        cands = {}
        while num > 0:
            for (k, v) in roman_dict.items():
                diff = num - v
                if diff >= 0:
                    cands[(k, v)] = diff
            best_diff = min(cands.values())
            best_key = list(cands.keys())[list(cands.values()).index(best_diff)][0]
            string += best_key
            num-= list(cands.keys())[list(cands.values()).index(best_diff)][1]
        return string
