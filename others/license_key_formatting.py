class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S = "".join(S.upper().split("-"))
        ret = ""
        S = S[::-1]
        cnt = 0
        for e in S:
            ret += e
            cnt += 1
            if cnt == K:
                ret += "-"
                cnt = 0
        if not cnt:
            ret = ret[:-1]
        return ret[::-1]

if __name__ == "__main__":
    sol = Solution()
    print(sol.licenseKeyFormatting("2-5g-3-J",2))
