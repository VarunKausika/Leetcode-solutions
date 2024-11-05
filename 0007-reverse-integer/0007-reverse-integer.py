class Solution:
    def reverse(self, x: int) -> int:
        def range_check(x: int) -> int:
            if x >= -2**31 and x <= 2**31 -1:
                return x
            else:
                return 0
        number_in_list_form = list(str(x))
        if number_in_list_form[0] == '-':
            reversed_number = -1*int(''.join(number_in_list_form[1::][::-1]))
            return range_check(reversed_number)
        else:
            reversed_number = int(''.join(number_in_list_form[::-1]))
            return range_check(reversed_number)
            