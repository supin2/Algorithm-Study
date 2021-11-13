#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    int romanToInt(string s) {
        int sum = 0, len = s.length();
        map<char, int> mp;
        
        mp['I'] = 1, mp['V'] = 5, mp['X'] = 10;
        mp['L'] = 50, mp['C'] = 100, mp['D'] = 500, mp['M'] = 1000;
        
        for (int i = len - 1; i >= 0; i--) {
            char ch = s[i];
            sum += mp[ch];
            if (i < len - 1) {
                if (ch == 'I') {
                    if (s[i + 1] == 'V' || s[i + 1] == 'X') {
                        sum -= 2;
                    }
                } else if (ch == 'X') {
                    if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                        sum -= 20;
                    }
                } else if (ch == 'C') {
                    if (s[i + 1] == 'D' || s[i + 1] == 'M') {
                        sum -= 200;
                    }
                }
            }
        }
        return sum;
    }
};