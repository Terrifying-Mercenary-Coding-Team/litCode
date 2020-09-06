class Solution(object):
    def partitionLabels(self, S):
        last = {c: i for i,c in enumerate(S)}
        st = 0
        j = 0
        ret = []
        for i in range(len(S)):
            cur = S[i]
            j = max(j, last[cur])
            if i == j:
                ret.append(i-st+1)
                st = i+1
        return ret
