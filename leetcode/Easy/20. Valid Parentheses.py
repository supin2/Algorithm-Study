class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        dic = {')':'(', '}':'{', ']':'['}
        
        for ch in s:
            if ch in dic.values():
                st.append(ch)
            elif ch in dic.keys():
                if st == [] or dic[ch] != st.pop():
                    return False
            else:
                return False
        return st == []