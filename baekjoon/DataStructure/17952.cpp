// 백준 17952번 : 과제는 끝나지 않아!
#include <bits/stdc++.h>

using namespace std;

struct Task {
    int score, burden;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, ans = 0;
    stack<Task> st;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int type;
        cin >> type;
        
        if (type) {
            int a, b;
            cin >> a >> b;
            if (b == 1) {
                ans += a;
            } else {
                st.push({ a, b - 1 });
            }
        } else {
            if (!st.empty()) {
                Task tmp = st.top();
                st.pop();
                tmp.burden--;
                
                if (tmp.burden == 0) {
                    ans += tmp.score;
                } else {
                    st.push(tmp);
                }
            }
        }
    }
    cout << ans;    
    return 0;
}