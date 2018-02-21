import string

class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        index = [s.find(c) for c in string.ascii_lowercase if s.count(c) == 1]
        return min(index) if index else -1


if __name__ == "__main__":
    print(Solution().firstUniqChar("leetcode"))
    print(Solution().firstUniqChar("loveleetcode"))
