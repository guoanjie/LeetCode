import bisect

class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = bisect.bisect_left(nums, target)
        r = bisect.bisect_right(nums, target)
        return [-1, -1] if l == r else [l, r - 1]


if __name__ == "__main__":
    print(Solution().searchRange([5, 7, 7, 8, 8, 10], 8))
