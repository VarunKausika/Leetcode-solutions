class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = list(s)
        stack = []
        running_max = 0
        longest_palindrome = ''
        for index, letter in enumerate(l):
            if index == 0:
                stack.append(letter)
                longest_palindrome = letter
                running_max = 1
                
            else:
                if letter not in stack:
                    stack.append(letter)
                elif letter in stack:
                    same_letter_indexes = [i for i, x in enumerate(stack) if x == letter]
                    stack.append(letter)
                    for i in sorted(same_letter_indexes):
                        substring_list = stack[i:]
                        if substring_list == substring_list[::-1]:
                            if len(substring_list) > running_max:
                                running_max = len(substring_list)
                                longest_palindrome = ''.join(substring_list)
                                break
        return longest_palindrome