from typing import List
from collections import OrderedDict

class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        hashdict = OrderedDict()
        for i,e in enumerate(S):
            if e not in hashdict:
                # start index, finish index
                hashdict[e] = [i,i]
            else:
                hashdict[e][1] = i

        for key,value in hashdict.items():
            s=value[0]
            f=value[1]
            for tar_key,tar_value in hashdict.items():
                if key==tar_key:
                    continue
                if s<=tar_value[0] and tar_value[1]<=f:
                    tar_value[0] = s
                    tar_value[1] = f
                if s<tar_value[0]<f or s<tar_value[1]<f:
                    s = tar_value[0] = min(s,tar_value[0])
                    f = tar_value[1] = max(f,tar_value[1])
                    
        ret = OrderedDict()
        for s,f in hashdict.values():
            if (s,f) not in ret:
                ret[(s,f)] = f-s+1

        ret = [val for val in ret.values()]
        return ret


if __name__ == "__main__":
    sol = Solution()
    print(sol.partitionLabels("ababcbacadefegdehijhklij"))
