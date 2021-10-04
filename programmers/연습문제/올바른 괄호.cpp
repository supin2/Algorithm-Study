#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for (char ch : s) {
        if (ch == '(') {
            st.push('(');
        } else {
            if (st.empty()) {
                return false;
            } else {
                if (st.top() != '(') {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
    }
    if (!st.empty()) {
        return false;
    }
    return answer;
}