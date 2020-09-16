class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_val = 987654321
        max_val = 0
        ret = 0
        for cur in prices:
            if cur < min_val:
                min_val = cur
                max_val = cur
            elif cur > max_val:
                max_val = cur
                ret = max(ret,max_val-min_val)
        return ret
