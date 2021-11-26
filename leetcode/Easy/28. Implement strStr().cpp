#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        
        if (nLen == 0) {
            return 0;
        }
        
        char firstChar = needle[0];
        int i;
        for (i = 0; i < hLen; i++) {
            char ch = haystack[i];
            if (ch == firstChar) {
                bool flag = true;
                for (int j = 1; j < nLen; j++) {
                    if (haystack[i + j] != needle[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            } else {
                continue;
            }
        }
        if (i == hLen) {
            return -1;
        } else {
            return i;
        }
    }
};