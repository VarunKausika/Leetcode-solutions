import numpy
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if target/2 not in nums:
            nums2 = set([target - i for i in nums])
            nums1 = set(nums)
            lst = [nums.index(i) for i in nums1.intersection(nums2)]
            return lst
        elif nums.count(target/2)==1:
            nums2 = set([target - i for i in nums])
            nums1 = set(nums)
            lst = [nums.index(i) for i in nums1.intersection(nums2) if i!=target/2]
            return lst
        else:
            return list(numpy.where(numpy.array(nums)==target/2)[0])
        
        
        
        
        
        