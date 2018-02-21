class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        letters = [' ', ' ', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        combinations = ['']
        for digit in map(int, digits):
            combinations = [c + d for c in combinations for d in letters[digit]]
        return [] if combinations == [''] else combinations


if __name__ == "__main__":
    print(Solution().letterCombinations("23"))
