import numpy as np

class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        beg = 0
        end = len(height) - 1
        area = 0
        while beg <= end:
            area = max(area, (end - beg) * min(height[beg], height[end]))
            if height[beg] < height[end]:
                beg += 1
            else:
                end -= 1
        return area


if __name__ == "__main__":
    print(Solution().maxArea(np.random.uniform(size=10)))
