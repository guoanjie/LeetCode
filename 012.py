class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        num   = list(map(int, str(num)[::-1]))
        ones  = ['I', 'X', 'C', 'M']
        fives = ['V', 'L', 'D']
        roman = ""
        for i in range(len(num))[::-1]:
            if num[i] % 5 == 4:
                roman += ones[i]
                num[i] += 1
            if num[i] == 10:
                roman += ones[i+1]
                num[i] = 0
            if num[i] >= 5:
                roman += fives[i]
                num[i] -= 5
            roman += ones[i] * num[i]
        return roman


if __name__ == "__main__":
    print(Solution().intToRoman(1776))
