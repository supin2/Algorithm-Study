// 백준 9375번 : 패션왕 신해빈
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int num;
        cin >> num;

        map<string, int> m;
        string a, b;
        for (int i = 0; i < num; i++) {
            cin >> a >> b;
            m[b]++;
        }
        if (m.size() == 1) {
            cout << m[b] << '\n';    
        } else {
            int ans = 1;
            for (auto it : m) {
                ans *= (it.second + 1);
            }
            cout << ans - 1 << '\n';
        }
    }
    return 0;
}