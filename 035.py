import bisect

class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        return bisect.bisect_left(nums, target)


if __name__ == "__main__":
    print(Solution().searchInsert([1, 3, 5, 6], 5))
    print(Solution().searchInsert([1, 3, 5, 6], 2))
    print(Solution().searchInsert([1, 3, 5, 6], 7))
    print(Solution().searchInsert([1, 3, 5, 6], 0))
