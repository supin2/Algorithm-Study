class Solution:
    def romanToInt(self, s: str) -> int:
        dic = { 'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000 }
        ret = 0
        
        for idx in range(len(s) - 1):
            if dic[s[idx]] < dic[s[idx + 1]]:
                ret -= dic[s[idx]]
            else:
                ret += dic[s[idx]]
        
        ret += dic[s[-1]]
        return ret