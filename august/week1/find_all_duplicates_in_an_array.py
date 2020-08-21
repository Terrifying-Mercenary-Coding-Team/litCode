from typing import List

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ret = []
        for e in nums:
            nums[abs(e)-1] *= -1
        for e in nums:
            if nums[abs(e)-1] > 0:
                ret.append(abs(e))
                nums[abs(e)-1] *= -1
        
        return ret 

if __name__ == "__main__":
    sol = Solution()
    print(sol.findDuplicates([4,3,2,7,8,2,3,1]))
