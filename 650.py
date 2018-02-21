class Solution:
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        steps = 0
        p = 2
        while n > 1:
            if n % p:
                p += 1
            else:
                n /= p
                steps += p
        return steps


if __name__ == "__main__":
    print(Solution().minSteps(3))
