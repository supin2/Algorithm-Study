class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        hsLen = len(haystack)
        nLen = len(needle)
        
        for i in range(hsLen - nLen + 1):
            if haystack[i:i+nLen] == needle:
                return i

        return -1