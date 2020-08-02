class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word == word.upper():
            return True
        elif word == word.lower():
            return True
        elif word[0].upper() == word[0] and word[1:] == word[1:].lower():
            return True
        else:
            return False
        

if __name__ == "__main__":
    sol = Solution()
    print(sol.detectCapitalUse("USA"))
    print(sol.detectCapitalUse("FlaG"))
