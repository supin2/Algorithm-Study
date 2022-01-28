class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        word = min(strs, key=len)
        
        for idx, ch in enumerate(word):
            for w in strs:
                if w[idx] != ch:
                    return word[:idx]
        return word