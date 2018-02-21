from functools import reduce
import operator
import string

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return reduce(operator.and_, (s.count(c) == t.count(c) for c in string.ascii_lowercase))

if __name__ == "__main__":
    print(Solution().isAnagram("anagram", "nagaram"))
    print(Solution().isAnagram("rat", "car"))
