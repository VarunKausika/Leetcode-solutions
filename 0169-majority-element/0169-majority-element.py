class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        maxcount = 0
        for i in set(nums):
            if nums.count(i) > maxcount:
                maxcount = nums.count(i)
                maxi = i
        return maxi