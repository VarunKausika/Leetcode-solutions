from itertools import product
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits)>0:
            alphabet = list(string.ascii_lowercase)
            alphabet_threes = list()
            i = 0
            while i<15:
                three = [alphabet[i:i+3]]
                alphabet_threes+=three
                i+=3
            alphabet_threes+=[alphabet[15:19], alphabet[19:22], alphabet[22:26]]
            numbers = range(2,10)
            mapping = dict(list(zip(numbers, alphabet_threes)))
            digit_letter_list = [mapping[int(digit)] for digit in digits]
            new_list = ["".join(i) for i in list(product(*digit_letter_list))]
            return new_list
        else:
            return []


