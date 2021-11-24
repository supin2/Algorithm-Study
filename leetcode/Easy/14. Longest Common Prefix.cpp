#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        
        string shortStr = strs[0];
        int minLen = strs[0].length();
        
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < minLen) {
                shortStr = strs[i];
                minLen = strs[i].length();
            }
        }
        
        bool prefixCheck = true;
        int i;
        for (i = 0; i < minLen; i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j] == shortStr) {
                    continue;
                }
                if (strs[j][i] != shortStr[i]) {
                    prefixCheck = false;
                    break;
                }
            }
            if (!prefixCheck) {
                break;
            }
        }
        
        return shortStr.substr(0, i);
    }
};