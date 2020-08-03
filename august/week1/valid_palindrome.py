import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = "".join(re.findall("[0-9a-zA-Z]", s))
        s = s.lower()
        return s==s[::-1]


if __name__ == "__main__":
    sol = Solution()
    print(sol.isPalindrome("A man, a plan, a canal: Panama"))
    print(sol.isPalindrome("race a car"))
    print(sol.isPalindrome("0P"))
