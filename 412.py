class Solution:
    def _fizz_buzz(self, n):
        repr  = "" if n % 3 else "Fizz"
        repr += "" if n % 5 else "Buzz"
        return repr if repr else str(n)

    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        return list(map(self._fizz_buzz, range(1, n+1)))


if __name__ == "__main__":
    print(Solution().fizzBuzz(15))
