#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    if (ch == ')') {
                        if (st.top() != '(') {
                            return false;
                        } else if (st.top() == '(') {
                            st.pop();
                        }
                    } else if (ch == '}') {
                        if (st.top() != '{') {
                            return false;
                        } else if (st.top() == '{') {
                            st.pop();
                        }
                    } else if (ch == ']') {
                        if (st.top() != '[') {
                            return false;
                        } else if (st.top() == '[') {
                            st.pop();
                        }
                    }
                }
            }
        }
        if (!st.empty()) {
            return false;
        } else {
            return true;
        }
    }
};