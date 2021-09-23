#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int isCorrect(string p, int *idx) {
    stack<char> st;
    int lp = 0, rp = 0;
    bool ret = true;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') {
            st.push('(');
            lp++;
        } else {
            if (st.empty()) {
                ret = false;
            } else {
                st.pop();
            }
            rp++;
        }
        if (lp == rp) {
            *idx = i + 1;
            return ret;
        }
    }
}

string solution(string p) {
    if (p.empty()) {
        return p;
    }
    int idx = 0;
    bool flag = isCorrect(p, &idx);
    string u = p.substr(0, idx);
    string v = p.substr(idx);
    string str = "";
    
    if (flag) {
        return u + solution(v);
    } else {
        str = "(" + solution(v) + ")";
        
        for (int i = 1; i < u.length() - 1; i++) {
            if (u[i] == '(') {
                str += ")";
            } else {
                str += "(";
            }
        }
    }
    return str;
}