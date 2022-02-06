class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ret = ''
        carry = 0
        
        a = list(a)
        b = list(b)
        
        while carry or a or b:
            if a:
                carry += int(a.pop())
            if b:
                carry += int(b.pop())
                
            ret += str(carry%2)
            carry //= 2
        
        return ret[::-1]