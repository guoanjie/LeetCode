import numpy as np

class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        return sum(max(prices[i] - prices[i-1], 0) for i in range(1, len(prices)))


if __name__ == "__main__":
    print(Solution().maxProfit(np.exp(np.cumsum(np.random.normal(size=10)))))
