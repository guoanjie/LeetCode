class Solution:
    def dfs(self, candidates, target, combinations, path):
        if target == 0:
            combinations.append(path)
        elif candidates and candidates[0] <= target:
            self.dfs(candidates[1:], target, combinations, path)
            self.dfs(candidates, target - candidates[0], combinations, path + [candidates[0]])

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        combinations = []
        self.dfs(candidates, target, combinations, [])
        return combinations


if __name__ == "__main__":
    print(Solution().combinationSum([2, 3, 6, 7], 7))
