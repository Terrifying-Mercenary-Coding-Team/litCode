from collections import defaultdict

class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        str_dict = str.split()
        if len(pattern) != len(str_dict):
            return False
        hashdict = defaultdict(set)
        for i in range(len(pattern)):
            hashdict[pattern[i]].add(str_dict[i])
        for val in hashdict.values():
            if len(val)!=1:
                return False
        return False if len(hashdict) != len(set(map(tuple,hashdict.values())))    else True
