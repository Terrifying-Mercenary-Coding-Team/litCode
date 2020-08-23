from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ret = set()
        for i in range(len(nums)):
            j,k = i+1, len(nums)-1
            tar = -1*nums[i]
            while j < k:
                cur = nums[j]+nums[k]
                if cur==tar:
                    ret.add((nums[i],nums[j],nums[k]))
                    j += 1
                    k -= 1
                elif cur<tar:
                    j += 1
                else:
                    k -= 1
        ret = [list(item) for item in ret]
        return ret 
                    
if __name__ == "__main__":
    sol = Solution()
    print(sol.threeSum([-1,0,1,2,-1,-4]))

