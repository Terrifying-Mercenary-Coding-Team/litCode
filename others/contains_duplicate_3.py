from collections import defaultdict
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if t<0:
           return False
        hashmap = defaultdict(list)
        for i in range(len(nums)):
            key = nums[i]//(t+1)
            if hashmap[key]:
                return True
            elif hashmap[key-1] and abs(nums[i]-hashmap[key-1][0])<=t:
                return True
            elif hashmap[key+1] and abs(nums[i]-hashmap[key+1][0])<=t:
                return True
            hashmap[key].append(nums[i])
            if i>=k:
                del_key = nums[i-k]//(t+1)
                hashmap[del_key].pop(0)
        return False
