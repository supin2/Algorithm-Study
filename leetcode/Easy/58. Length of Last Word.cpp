#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            char ch = s[i];
            if (ch == ' ') {
                if (temp == "") {
                    continue;
                } else {
                    break;
                }
            } else {
                temp += ch;
            }
        }
        return temp.length();
    }
};