#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int size = digits.size();
        vector<int> ret;
        
        for (int i = size - 1; i >= 0; i--) {
            int num = digits[i];
            
            if (num == 9 && carry == 1) {
                ret.push_back(0);
                carry = 1;
            } else {
                ret.push_back(num + carry);
                carry = 0;
            }
        }
        if (carry == 1) {
            ret.push_back(1);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};