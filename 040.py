import bisect

class Solution:
    def dfs(self, candidates, target, combinations, path):
        if target == 0:
            combinations.append(path)
        elif candidates and candidates[0] <= target:
            self.dfs(candidates[bisect.bisect_right(candidates, candidates[0]):], target, combinations, path)
            self.dfs(candidates[1:], target - candidates[0], combinations, path + [candidates[0]])

    def combinationSum2(self, candidates, target):
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
    print(Solution().combinationSum2([10, 1, 2, 7, 6, 1, 5], 8))
