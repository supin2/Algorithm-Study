class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x >= 0 && x < 10) {
            return true;
        }
        
        long long rev = 0, tmp = x;
        
        while (tmp != 0) {
            int num = tmp % 10;
            rev = rev*10 + num;
            tmp /= 10;
        }
        
        if (rev == x) {
            return true;
        } else {
            return false;   
        }
    }
};