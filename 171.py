class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = 0
        for t in list(s):
            n = n * 26 + ord(t) - ord('A') + 1
        return n


if __name__ == "__main__":
    print(Solution().titleToNumber("AB"))
