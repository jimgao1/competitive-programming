class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        N = len(prices)
        p = 1e9
        dp1, dp2 = [0] * N, [0] * N

        for i in range(N):
            p = min(p, prices[i])
            dp1[i] = max(dp1[i - 1], prices[i] - p) if i > 0 else prices[i] - p

        p = 0
        for i in range(N - 1, 0, -1):
            p = max(p, prices[i])
            dp2[i] = max(dp2[i + 1], p - prices[i]) if i < N - 1 else p - prices[i]

        ret = 0
        for i in range(N - 1):
            ret = max(ret, dp1[i] + dp2[i + 1])

        for i in range(N):
            ret = max(ret, dp1[i])

        return ret


A = Solution()
assert 6 == A.maxProfit([3, 3, 5, 0, 0, 3, 1, 4])
assert 4 == A.maxProfit([1, 2, 3, 4, 5])
assert 0 == A.maxProfit([7, 6, 4, 3, 1])
