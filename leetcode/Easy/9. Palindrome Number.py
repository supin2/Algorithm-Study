class Solution:   
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x > 0 and x % 10 == 0):
            return False
        
        return x == self.reverseNumber(x)
    
    def reverseNumber(self, x: int) -> int:
        num = 0
        
        while x > 0:
            num = num*10 + x%10
            x //= 10
            
        return num