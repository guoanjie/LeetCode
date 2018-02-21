class Solution:
    def dfs(self, n, l, parenthesis, path):
        r = len(path) - l
        if r == n:
            parenthesis.append(path)
        if l < n:
            self.dfs(n, l + 1, parenthesis, path + '(')
        if l > r:
            self.dfs(n, l, parenthesis, path + ')')

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        parenthesis = []
        self.dfs(n, 0, parenthesis, "")
        return parenthesis


if __name__ == "__main__":
    print(Solution().generateParenthesis(3))
