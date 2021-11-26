#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aIdx = a.length() - 1, bIdx = b.length() - 1;
        int carry = 0;
        string ret = "";
        
        while (aIdx >= 0 || bIdx >= 0 || carry == 1) {
            int n1 = aIdx >= 0 ? a[aIdx] - '0' : 0;
            int n2 = bIdx >= 0 ? b[bIdx] - '0' : 0;
            int sum = n1 + n2 + carry;
            
            carry = sum / 2;
            ret += (sum % 2) + '0';
            
            aIdx--;
            bIdx--;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};