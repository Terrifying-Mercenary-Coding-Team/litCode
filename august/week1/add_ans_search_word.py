class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hash = dict()
        self.token = "."
        

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        cur = self.hash
        for i, w in enumerate(word):
            if w not in cur:
                if i == len(word)-1:
                    cur[w] = dict([(1,dict())])
                else:
                    cur[w] = dict()
            cur = cur[w]

    def dfs(self, word: str, ind: int, cur):
        if ind == len(word):
            if 1 in cur:                
                return True
            else:
                return False

        if word[ind] == self.token:
            flag = False
            for key in cur.keys():
                flag |= self.dfs(word, ind+1, cur[key])
            return flag

        else:
            if word[ind] not in cur:
                return False
            else:
                return self.dfs(word, ind+1, cur[word[ind]])

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self.dfs(word, 0, self.hash)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)

if __name__ == "__main__":
    word_dict = WordDictionary()
    word_dict.addWord("a")
    word_dict.addWord("a")
    print(word_dict.search("."))
    print(word_dict.search("a"))
    print(word_dict.search("aa"))
    print(word_dict.search("a"))
    print(word_dict.search(".a"))
    print(word_dict.search("a."))
    '''
["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]
[[],
["at"],["and"],["an"],["add"],
["a"],[".at"],
["bat"],
[".at"],["an."],["a.d."],["b."],["a.d"],["."]]


["WordDictionary","addWord","addWord","search","search","search","search","search","search"]
[[],["a"],["a"],["."],["a"],["aa"],["a"],[".a"],["a."]]
    '''
