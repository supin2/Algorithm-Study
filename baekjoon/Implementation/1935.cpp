// 백준 1935번 : 후위 표기식2
#include <bits/stdc++.h>

using namespace std;

int alpha[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    string expr;
    cin >> N >> expr;
    
    for (int i = 0; i < N; i++) {
        cin >> alpha[i];
    }
    stack<double> st;
    for (char ch : expr) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            double num1 = st.top();
            st.pop();
            double num2 = st.top();
            st.pop();
            
            if (ch == '+') {
                st.push(num2 + num1);
            } else if (ch == '-') {
                st.push(num2 - num1);
            } else if (ch == '*') {
                st.push(num2 * num1);
            } else if (ch == '/') {
                st.push(num2 / num1);
            }
        } else {
            st.push(alpha[ch - 'A']);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << st.top();
    return 0;
}
