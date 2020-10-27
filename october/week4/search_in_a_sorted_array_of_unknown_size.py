# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader:
#    def get(self, index: int) -> int:

class Solution:
    def __init__(self):
        super().__init__()
        self.delim_out = 2147483647

    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        st = 0
        ed = 10000
        while st <= ed:
            mid = (st+ed) // 2
            cur = reader.get(mid)
            if cur == target:
                return mid

            elif cur < target:
                st = mid + 1
                
            else:
                ed = mid - 1

        return -1 
