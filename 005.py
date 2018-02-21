class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        maxlen = 0
        maxbeg = 0
        maxend = 0
        for i in range(len(s)):
            if i > 0 and s[i] == s[i-1]:
                continue
            beg = i
            end = beg + 1
            while end < len(s) and s[beg] == s[end]:
                end += 1
            while beg > 0 and end < len(s) and s[beg-1] == s[end]:
                beg -= 1
                end += 1
            if end - beg > maxlen:
                maxlen = end - beg
                maxbeg = beg
                maxend = end
        return s[maxbeg:maxend]


if __name__ == "__main__":
    print(Solution().longestPalindrome("babad"))
    print(Solution().longestPalindrome("cbbd"))
