class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s[::-1]


if __name__ == "__main__":
    print(Solution().reverseString("hello"))
