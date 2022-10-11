import sys
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for num in nums:
            if target<=num:
                return nums.index(num)
                sys.exit()
        return len(nums)