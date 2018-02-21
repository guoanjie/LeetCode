class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = 0
        for b, o, f, t in [
            (1000, 'M', '?', '?'),
            ( 100, 'C', 'D', 'M'),
            (  10, 'X', 'L', 'C'),
            (   1, 'I', 'V', 'X'),
        ]:
            if s.startswith(o + t):
                n += 9 * b
                s = s[2:]
            elif s.startswith(o + f):
                n += 4 * b
                s = s[2:]
            elif s.startswith(f):
                n += 5 * b
                s = s[1:]
            while s.startswith(o):
                n += b
                s = s[1:]
        return n


if __name__ == "__main__":
    print(Solution().romanToInt("MDCCLXXVI"))
