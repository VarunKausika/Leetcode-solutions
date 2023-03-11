class Solution:
    def maxArea(self, height: List[int]) -> int:
        if len(height)>0:
            start = 0
            end = len(height)-1
            area = 0
            while start < end:
                h = min([height[start], height[end]])
                new_area = (end - start)*h
                if new_area > area:
                    area = new_area
                if height[start] >= height[end]:
                    end -=1
                else:
                    start += 1
            return area
        else:
            return 0
