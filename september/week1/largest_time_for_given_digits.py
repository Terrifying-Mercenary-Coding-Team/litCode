from typing import List
from functools import cmp_to_key

class Solution:
    def __init__(self):
        self.cands = []
        self.visited = [False]*4

    def make_permutations(self, A: List[int], cur):
        if len(cur) == 4:
            self.cands.append(cur[:])
            return
        for i in range(4):
            if self.visited[i]:
                continue
            cur.append(A[i])
            self.visited[i] = True
            self.make_permutations(A,cur)
            self.visited[i] = False
            cur.pop()

    def make_combinations(self, A: List[int], cur, ind):
        if len(cur) ==4:
            self.cands.append(cur[:])
            return
        for i in range(ind,4):
            cur.append(A[i])
            self.make_combinations(A,cur,i+1)
            cur.pop()

    def is_valid(self, A: List[int]):
        for i, val in enumerate(A):
            if i == 0:
                if val > 2:
                    return False
            elif i == 1:
                if A[0] == 2 and val > 3:
                    return False

            elif i == 2:
                if val > 5:
                    return False

        return True

    def largestTimeFromDigits(self, A: List[int]) -> str:
        self.cands = []
        self.visited = [False]*4
        self.make_permutations(A,[])
        self.cands = list(filter(self.is_valid, self.cands))
        self.cands = sorted(self.cands, key=lambda x: x[0]*600+x[1]*60+x[2]*10+x[3])
        if not self.cands:
            return ""
        ret = "".join(map(str,self.cands[-1]))
        ret = ret[:2] + ":" + ret[2:] 
        return ret

if __name__ == "__main__":
    sol = Solution()
    print(sol.largestTimeFromDigits([1,2,3,4]))
    print(sol.largestTimeFromDigits([0,4,0,0]))
    print(sol.largestTimeFromDigits([2,0,6,6]))
    print(sol.largestTimeFromDigits([5,5,5,5]))

