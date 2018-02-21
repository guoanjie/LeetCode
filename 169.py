class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sorted(nums)[len(nums) // 2]


if __name__ == "__main__":
    print(Solution().majorityElement([1, 2, 2]))
