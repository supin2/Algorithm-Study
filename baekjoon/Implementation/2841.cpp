// 백준 2841번 : 외계인의 기타 연주
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, P, ans = 0;
    cin >> N >> P;
    
    stack<int> st[7];
    
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        
        if (st[a].empty()) {
            st[a].push(b);
            ans++;
        } else {
            if (st[a].top() < b) {
                st[a].push(b);
                ans++;
            } else {
                while (!st[a].empty() && st[a].top() > b) {
                    st[a].pop();
                    ans++;
                }
                if (st[a].empty()) {
                    st[a].push(b);
                    ans++;
                } else {
                    if (st[a].top() == b) {
                        continue;
                    } else {
                        st[a].push(b);
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
