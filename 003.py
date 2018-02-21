class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        beg = 0
        end = 0
        longest = 0
        used = {}
        while end < len(s):
            if used.get(s[end], False):
                used[s[beg]] = False
                beg += 1
            else:
                used[s[end]] = True
                end += 1
                longest = max(longest, end - beg)
        return longest


if __name__ == "__main__":
    print(Solution().lengthOfLongestSubstring("abcabcbb"))
    print(Solution().lengthOfLongestSubstring("bbbbb"))
    print(Solution().lengthOfLongestSubstring("pwwkew"))
