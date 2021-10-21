// 백준 10799번 : 쇠막대기
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str;
    stack<char> st;

    cin >> str;

    int ans = 0;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == '(') {
            st.push('(');
        } else if (ch == ')') {
            st.pop();
            if (str[i - 1] == '(') {
                ans += st.size();
            } else {
                ans += 1;
            }
        }
    }
    cout << ans;
    return 0;
}