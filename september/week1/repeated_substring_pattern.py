class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        dp = [0]*n
        i=1;j=0
        while i<n:
            while j>0 and s[i] != s[j]:
                j = dp[j-1]
            if s[i] == s[j]:
                j += 1
                dp[i] += j
            i += 1
        cutn = n-dp[n-1]
        tar = s[:cutn]
        if cutn==n or n%cutn:
            return False
        else:
            if tar*(n//cutn) == s:
                return True
            else:
                return False

if __name__ == "__main__":
    sol = Solution()
    print(sol.repeatedSubstringPattern("abab"))
    print(sol.repeatedSubstringPattern("aba"))
    print(sol.repeatedSubstringPattern("abcabcabcabc"))
    print(sol.repeatedSubstringPattern("abac"))
