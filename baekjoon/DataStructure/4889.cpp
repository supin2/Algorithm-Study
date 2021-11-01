// 백준 4889번 : 안정적인 문자열
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for (int i = 1; ; i++) {
        int ans = 0;
        string str;
        stack<char> st;
        
        cin >> str;
        if (str[0] == '-') {
            break;
        }
        for (char ch : str) {
            if (ch == '{') {
                st.push('{');
            } else if (ch == '}') {
                if (st.empty()) {
                    st.push('}');
                } else {
                    if (st.top() == '{') {
                        st.pop();
                    } else {
                        st.push('}');
                    }
                }
            }
        }
        while (!st.empty()) {
            char ch1 = st.top();
            st.pop();
            char ch2 = st.top();
            st.pop();
            
            if (ch1 == ch2) {
                ans += 1;
            } else {
                ans += 2;
            }
        }
        cout << i << ". " << ans <<'\n';
    }
    return 0;
}
