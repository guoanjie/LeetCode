import itertools

class Solution:
    def dfs(self, nums, permutations, path):
        if not nums:
            permutations.append(path)
        else:
            for i in range(len(nums)):
                if i == 0 or nums[i-1] < nums[i]:
                    self.dfs(nums[:i] + nums[i+1:], permutations, path + [nums[i]])

    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        permutations = []
        self.dfs(nums, permutations, [])
        return permutations


if __name__ == "__main__":
    print(Solution().permuteUnique([1, 1, 2]))
