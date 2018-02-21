class Solution:
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return bool(n & 3)


if __name__ == "__main__":
    print(Solution().canWinNim(4))
