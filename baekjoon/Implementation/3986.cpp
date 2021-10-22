// 백준 3986번 : 좋은 단어
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, ans = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        
        stack<char> st;
        for (int j = 0; j < str.length(); j++) {
            char ch = str[j];
            
            if (st.empty()) {
                st.push(ch);
            } else {
                if (st.top() == ch) {
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
        }
        if (st.empty()) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
